#include "standard_brushes.h"
#include <cmath>

void GrabBrush::Apply(Mesh& mesh, int vertexIndex, const float origin[3]) {
    // Simple grab: move directly along X by baseStrength
    float delta[3] = { baseStrength, 0.0f, 0.0f };
    mesh.ApplyDeformation(vertexIndex, delta);
}

void SmoothBrush::Apply(Mesh& mesh, int vertexIndex, const float origin[3]) {
    // Smooths a vertex by averaging with neighbors (basic version)
    // See previous examples for neighbor-finding code
    // Call mesh.ApplyDeformation(...) with the smoothing delta
}
