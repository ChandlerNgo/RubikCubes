#ifndef CUBEDEFS_H
#define CUBEDEFS_H

#include <array>
#include <glm/glm.hpp>

enum CubeFace { FRONT, BACK, LEFT, RIGHT, TOP, BOTTOM, FACE_COUNT };
enum CubeColor { RED, GREEN, BLUE, ORANGE, WHITE, YELLOW, COLOR_COUNT };

constexpr std::array<glm::vec3, COLOR_COUNT> cubeColors = {{
    {1.0f, 0.0f, 0.0f}, // RED
    {0.0f, 1.0f, 0.0f}, // GREEN
    {0.0f, 0.0f, 1.0f}, // BLUE
    {1.0f, 0.5f, 0.0f}, // ORANGE
    {1.0f, 1.0f, 1.0f}, // WHITE
    {1.0f, 1.0f, 0.0f}  // YELLOW
}};

constexpr glm::vec3 getCubeColor(int color) {
    return (color >= 0 && color < COLOR_COUNT)
        ? cubeColors[color]
        : glm::vec3(0.0f);
}

#endif