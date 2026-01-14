#ifndef BRUSH_INPUT_H
#define BRUSH_INPUT_H

struct BrushInput {
    float pressure = 1.0f;  // 1.0 for mouse, 0.0–1.0 for tablet
    float location[3] = {0.0f, 0.0f, 0.0f}; // world-space location of the brush
    int vertexIndex = -1; // optional precomputed nearest vertex index
};

#endif