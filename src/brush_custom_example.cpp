#include "brush_custom_example.h"
#include <cmath>

void CustomPinchBrush::Apply(Mesh& mesh, int vertexIndex, const float origin[3]) {
    // Example: Pinch moves vertex toward the origin with user strength map
    float* v = mesh.vertices[vertexIndex].position;
    float dist = std::sqrt((v[0]-origin[0])*(v[0]-origin[0]) + (v[1]-origin[1])*(v[1]-origin[1]) + (v[2]-origin[2])*(v[2]-origin[2]));
    float scale = baseStrength;
    if (strengthProfile) scale *= strengthProfile(dist, radius, baseStrength);
    float delta[3] = { (origin[0] - v[0]) * scale,
                       (origin[1] - v[1]) * scale,
                       (origin[2] - v[2]) * scale};
    mesh.ApplyDeformation(vertexIndex, delta);
}
