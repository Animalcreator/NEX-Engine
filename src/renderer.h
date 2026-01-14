#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include "brush_input.h"

class Renderer {
public:
    bool Initialize();
    void Render();
    void Shutdown();

    // Real-time preview overlay for the sculpt brush
    void DrawBrushPreview(const BrushInput& input, float radius);
};

#endif