#ifndef BRUSH_BASE_H
#define BRUSH_BASE_H

#include <string>
#include <vector>
#include <functional>
#include "mesh.h"

using StrengthFunction = std::function<float(float distance, float radius, float baseStrength)>;

class Mesh;

class SculptBrush {
public:
    std::string name;
    float baseStrength = 1.0f; // Default overall strength
    StrengthFunction strengthProfile; // User-customizable per-brush strength curve
    float radius = 1.0f;

    enum BrushType {
        GRAB,
        SMOOTH,
        INFLATE,
        CUSTOM
    } type;

    SculptBrush(const std::string& n, BrushType t, float strength = 1.0f, float r = 1.0f,
                StrengthFunction fn = nullptr)
        : name(n), type(t), baseStrength(strength), radius(r), strengthProfile(fn) {}

    // Core API for all sculpt brushes
    virtual void Apply(Mesh& mesh, int vertexIndex, const float origin[3]) = 0;

    virtual ~SculptBrush() = default;
};

#endif
