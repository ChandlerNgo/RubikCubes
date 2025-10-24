#include "RubikCube.h"
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

RubikCube::RubikCube(int n) : size(n){
    float offset = size / 2.0f;
    for (int z = 0; z < size; z++){
        for (int y = 0; y < size; y++){
            for (int x = 0; x < size; x++){
                float px = x - offset;
                float py = y - offset;
                float pz = z - offset;

                Cube cube({px, py, pz});

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
    glm::vec3 rotationAxis;

    if(axis == 'x'){
        rotationAxis = glm::vec3(1,0,0);
    }else if(axis == 'y'){
        rotationAxis = glm::vec3(0,1,0);
    }else{
        rotationAxis = glm::vec3(0,0,1);
    }

    glm::vec3 layerCenter(0.5f);

    for(int i = 0; i < (int)cubes.size(); i++){
        int x = i % size;
        int y = (i / size) % size;
        int z = i / (size * size);

        bool inLayer = (axis == 'x' && x == layerIndex) || (axis == 'y' && y == layerIndex) || (axis == 'z' && z == layerIndex);
        if (inLayer) {
            cubes[i].modelMatrix = glm::translate(cubes[i].modelMatrix, -layerCenter);
            cubes[i].modelMatrix = glm::rotate(cubes[i].modelMatrix, glm::radians(angle), rotationAxis);
            cubes[i].modelMatrix = glm::translate(cubes[i].modelMatrix, layerCenter);
        }
    }
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