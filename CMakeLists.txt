cmake_minimum_required(VERSION 3.15)
project(AudioVisualizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ImGui source files
set(IMGUI_SOURCES
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/backends/imgui_impl_opengl3.cpp
    imgui/backends/imgui_impl_glfw.cpp
)

# Find packages
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Add the executable
add_executable(${PROJECT_NAME} src/main.cpp ${IMGUI_SOURCES})

# Include directories for ImGui and SDL2
target_include_directories(${PROJECT_NAME} PRIVATE
    imgui
    imgui/backends
    ${SDL2_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
    OpenGL::GL
    glfw
    ${SDL2_LIBRARIES}
)