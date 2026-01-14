#include "gui.h"
#include <iostream>

void GUI::Render(BrushLibrary& brushes, std::string& selectedBrush, float& radius, float& strength, float& previewPressure) {
    // Console-based stub for demonstration. Replace with ImGui code when integrating.
    std::cout << "\n--- NEX Engine Sculpt GUI ---\n";
    std::cout << "Available brushes:";
    for (const auto& kv : brushes.brushes) std::cout << " " << kv.first;
    std::cout << "\nSelected: " << selectedBrush << "\n";
    std::cout << "Radius: " << radius << " | Strength: " << strength << " | Pressure Preview: " << previewPressure << "\n";
    std::cout << "(Use actual GUI to change these values in a final integration)\n";
}