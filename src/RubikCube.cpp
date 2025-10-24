#include "RubikCube.h"
#include <vector>
#include <glm/glm.hpp>

RubikCube::RubikCube(int n) : size(n){
    for (int x = 0; x < size; x++){
        for (int y = 0; y < size; y++){
            for (int z = 0; z < size; z++){
                Cube cube({x,y,z});

                cube.setFaceColor(FRONT, GREEN);
                cube.setFaceColor(BACK, BLUE);
                cube.setFaceColor(LEFT, ORANGE);
                cube.setFaceColor(RIGHT, RED);
                cube.setFaceColor(TOP, WHITE);
                cube.setFaceColor(BOTTOM, YELLOW);

                cubes.push_back(cube);
            }
        }
    }
}

void RubikCube::rotateLayer(int layerIndex, char axis, float angle){
    // Implementation of layer rotation logic goes here
    return;
}

void RubikCube::setCubeFaceColor(int x, int y, int z, CubeFace face, int color){
    int idx = index(x, y, z);
    if (idx >= 0 && idx < (int)cubes.size()){
        cubes[idx].setFaceColor(face, color);
    }
}
void RubikCube::generateVertexData(std::vector<float>& positions, std::vector<float>& colors) const{
    for (const auto& cube : cubes){
        cube.generateData(positions, colors);
    }
}