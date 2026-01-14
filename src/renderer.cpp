#include "renderer.h"
#include <iostream>

bool Renderer::Initialize() {
    std::cout << "Initializing Renderer...\n";
    // Placeholder for graphics library initialization
    return true;
}

void Renderer::Render() {
    std::cout << "Rendering a frame...\n";
}

void Renderer::Shutdown() {
    std::cout << "Shutting down Renderer...\n";
}

void Renderer::DrawBrushPreview(const BrushInput& input, float radius) {
    // Stub preview: in a real renderer this would draw a circle/soft falloff volume on top of the mesh
    std::cout << "[Brush Preview] center=(" << input.location[0] << ", " << input.location[1] << ", " << input.location[2] << ")"
              << " radius=" << radius << " pressure=" << input.pressure << "\n";
}