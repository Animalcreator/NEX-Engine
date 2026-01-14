#include "engine.h"

bool Engine::Initialize() {
    std::cout << "Initializing Engine...\n";
    renderer = std::make_unique<Renderer>();
    input = std::make_unique<Input>();

    if (!renderer->Initialize()) {
        std::cerr << "Failed to initialize renderer.\n";
        return false;
    }

    isRunning = true;
    return true;
}

void Engine::Run() {
    std::cout << "Running Engine...\n";
    while (isRunning) {
        input->ProcessInput();
        renderer->Render();
    }
}

void Engine::Shutdown() {
    std::cout << "Shutting down Engine...\n";
    renderer->Shutdown();
}