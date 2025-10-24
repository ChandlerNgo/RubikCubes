#ifndef RUBIKCUBE_H
#define RUBIKCUBE_H

#include <vector>
#include <glm/glm.hpp>
#include "CubeDefs.h"
#include "Cube.h"

class RubikCube {
public:
    int size;
    std::vector<Cube> cubes;

    int index(int x, int y, int z) const { return x + y*size + z*size*size; }

    RubikCube(int size = 3);

    void rotateLayer(int layerIndex, char axis, float angle);
    void setCubeFaceColor(int x, int y, int z, CubeFace face, int color);
    void generateVertexData(std::vector<float>& positions, std::vector<float>& colors) const;
};

#endif