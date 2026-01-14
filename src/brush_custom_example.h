#ifndef BRUSH_CUSTOM_EXAMPLE_H
#define BRUSH_CUSTOM_EXAMPLE_H

#include "brush_base.h"

class CustomPinchBrush : public SculptBrush {
public:
    CustomPinchBrush(float intensity, StrengthFunction map)
        : SculptBrush("Pinch", CUSTOM, intensity, 1.0f, map) {}
    void Apply(Mesh& mesh, int vertexIndex, const float origin[3]) override;
};

#endif
