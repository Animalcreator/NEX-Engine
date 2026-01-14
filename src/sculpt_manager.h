#ifndef SCULPT_MANAGER_H
#define SCULPT_MANAGER_H

#include <memory>
#include <stack>
#include <vector>
#include "mesh.h"
#include "brush_base.h"
#include "brush_library.h"
#include "brush_input.h"
#include "sculpt_command.h"

class SculptManager {
public:
    Mesh mesh;
    // Pointer to the currently-active brush. Owned by BrushLibrary; SculptManager does not own it.
    SculptBrush* activeBrush = nullptr;

    // Undo/redo stacks
    std::stack<SculptCommand> undoStack;
    std::stack<SculptCommand> redoStack;

    SculptManager();

    // Select brush by pointer (from BrushLibrary)
    void SetActiveBrush(SculptBrush* brush) { activeBrush = brush; }

    // Perform sculpt using the brush with given input and user strength override.
    void Sculpt(const BrushInput& input, float userStrength);

    // Undo/Redo operations
    void Undo();
    void Redo();
};

#endif