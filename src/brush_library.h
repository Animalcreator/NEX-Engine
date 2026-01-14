#ifndef BRUSH_LIBRARY_H
#define BRUSH_LIBRARY_H

#include <map>
#include <memory>
#include "brush_base.h"

class BrushLibrary {
public:
    std::map<std::string, std::unique_ptr<SculptBrush>> brushes;

    // Register a new user/custom brush
    void RegisterBrush(std::unique_ptr<SculptBrush> brush) {
        brushes[brush->name] = std::move(brush);
    }

    // Select an existing brush by name
    SculptBrush* GetBrush(const std::string& name) {
        if (brushes.count(name)) return brushes[name].get();
        return nullptr;
    }
};

#endif
