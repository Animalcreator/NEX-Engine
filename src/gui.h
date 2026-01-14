#ifndef GUI_H
#define GUI_H

#include <string>
#include "brush_library.h"

class GUI {
public:
    // Render GUI controls. In a real integration replace console stubs with ImGui calls.
    // selectedBrush: name of currently selected brush
    // radius: brush radius (modifiable by GUI)
    // strength: brush base strength (modifiable by GUI)
    // previewPressure: simulated pressure preview from GUI (0.0 - 1.0)
    void Render(BrushLibrary& brushes, std::string& selectedBrush, float& radius, float& strength, float& previewPressure);
};

#endif