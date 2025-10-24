#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <glm/glm.hpp>
#include "CubeDefs.h"

class Cube{
public:
    glm::vec3 position;
    glm::vec3 faceColors[6];
    glm::mat4 modelMatrix = glm::mat4(1.0f);

    Cube(glm::vec3 pos);
    Cube(glm::vec3 pos, std::vector<int> col);

    void setFaceColor(int faceIndex, int color);

    void generateData(std::vector<float>& positions, std::vector<float>& colors) const;
};

#endif