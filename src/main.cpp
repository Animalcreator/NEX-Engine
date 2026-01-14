#include "engine.h"

int main() {
    Engine engine;
    if (engine.Initialize()) {
        engine.Run();
    }
    engine.Shutdown();
    return 0;
}