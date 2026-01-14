cmake_minimum_required(VERSION 3.10)
project(NEX-Engine)

set(CMAKE_CXX_STANDARD 17)
set(SRC
    src/main.cpp
    src/engine.cpp
    src/renderer.cpp
    src/input.cpp
    src/mesh.cpp
    src/renderer.cpp
    src/brush_base.h
    src/brush_library.h
    src/standard_brushes.cpp
    src/brush_custom_example.cpp
    src/brush_input.h
    src/sculpt_command.h
    src/sculpt_manager.cpp
    src/gui.cpp
)

# NOTE: header-only and previously added source files assumed; adjust list as needed.
add_executable(nex_engine ${SRC})

# No external deps for these stubs. For ImGui integration, link imgui sources/libraries here.
