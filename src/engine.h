#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <memory>
#include "renderer.h"
#include "input.h"

class Engine {
public:
    bool Initialize();
    void Run();
    void Shutdown();

private:
    bool isRunning = false;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Input> input;
};

#endif