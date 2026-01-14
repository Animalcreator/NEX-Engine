#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>

class Renderer {
public:
    bool Initialize();
    void Render();
    void Shutdown();
};

#endif