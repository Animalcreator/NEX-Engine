#ifndef SCULPT_COMMAND_H
#define SCULPT_COMMAND_H

#include <vector>
#include <array>
#include "mesh.h"

// Record changes for multiple vertices performed by a single sculpt action.
class SculptCommand {
public:
    struct Change {
        int vertexIndex;
        std::array<float,3> before;
        std::array<float,3> after;
    };

    std::vector<Change> changes;

    SculptCommand() = default;
    explicit SculptCommand(std::vector<Change>&& c) : changes(std::move(c)) {}

    void Undo(Mesh& mesh) {
        for (const auto& ch : changes) {
            for (int i = 0; i < 3; ++i) mesh.vertices[ch.vertexIndex].position[i] = ch.before[i];
        }
    }
    void Redo(Mesh& mesh) {
        for (const auto& ch : changes) {
            for (int i = 0; i < 3; ++i) mesh.vertices[ch.vertexIndex].position[i] = ch.after[i];
        }
    }
};

#endif