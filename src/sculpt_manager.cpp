#include "sculpt_manager.h"
#include <cmath>
#include <iostream>

SculptManager::SculptManager() : activeBrush(nullptr) {}

void SculptManager::Sculpt(const BrushInput& input, float userStrength) {
    if (!activeBrush) return;

    // Save original baseStrength so we can restore it after operation
    float originalBase = activeBrush->baseStrength;
    // Apply pressure and user-supplied strength multiplier
    activeBrush->baseStrength = originalBase * userStrength * input.pressure;

    std::vector<SculptCommand::Change> changes;
    const float* origin = input.location;
    float radius = activeBrush->radius;

    // For now: iterate all vertices and apply the brush to those within radius.
    for (size_t vi = 0; vi < mesh.vertices.size(); ++vi) {
        float* vp = mesh.vertices[vi].position;
        float dx = vp[0] - origin[0];
        float dy = vp[1] - origin[1];
        float dz = vp[2] - origin[2];
        float dist = std::sqrt(dx*dx + dy*dy + dz*dz);
        if (dist <= radius) {
            SculptCommand::Change ch;
            ch.vertexIndex = static_cast<int>(vi);
            ch.before = { vp[0], vp[1], vp[2] };

            // Optionally, modulate brush strength by profile
            // Many brushes use the strengthProfile internally - brush->Apply may already consult it.
            activeBrush->Apply(mesh, static_cast<int>(vi), origin);

            // Record after
            ch.after = { mesh.vertices[vi].position[0], mesh.vertices[vi].position[1], mesh.vertices[vi].position[2] };
            changes.push_back(ch);
        }
    }

    if (!changes.empty()) {
        // Push undo command and clear redo stack
        undoStack.push(SculptCommand(std::move(changes)));
        while (!redoStack.empty()) redoStack.pop();
    }

    // Restore original base strength
    activeBrush->baseStrength = originalBase;
}

void SculptManager::Undo() {
    if (undoStack.empty()) return;
    SculptCommand cmd = undoStack.top(); undoStack.pop();
    cmd.Undo(mesh);
    redoStack.push(cmd);
}

void SculptManager::Redo() {
    if (redoStack.empty()) return;
    SculptCommand cmd = redoStack.top(); redoStack.pop();
    cmd.Redo(mesh);
    undoStack.push(cmd);
}