#ifndef STANDARD_BRUSHES_H
#define STANDARD_BRUSHES_H

#include "brush_base.h"

// Example brush: grab
class GrabBrush : public SculptBrush {
public:
    GrabBrush() : SculptBrush("Grab", GRAB) {}
    void Apply(Mesh& mesh, int vertexIndex, const float origin[3]) override;
};

// Example brush: smooth
class SmoothBrush : public SculptBrush {
public:
    SmoothBrush() : SculptBrush("Smooth", SMOOTH) {}
    void Apply(Mesh& mesh, int vertexIndex, const float origin[3]) override;
};

#endif
