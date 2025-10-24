#include <vector>
#include <glm/glm.hpp>
#include "Cube.h"
#include <iostream>

Cube::Cube(glm::vec3 pos) : position(pos){
    for(int i = 0; i < 6; i++){
        faceColors[i] = {1.0f, 1.0f, 1.0f};
    }
}

Cube::Cube(glm::vec3 pos, std::vector<int> col) : position(pos){
    for(int i = 0; i < 6; i++){
        faceColors[i] = getCubeColor(col[i]);
    }
}

void Cube::setFaceColor(int faceIndex, int color){
    faceColors[faceIndex] = getCubeColor(color);
}

void Cube::generateData(std::vector<float>& positions, std::vector<float>& colors) const{
    float x = position.x, y = position.y, z = position.z;
    float s = 0.45f;

    float faceVertices[6][6][3] = {
        // front
        {{x-s,y-s,z+s},{x+s,y-s,z+s},{x+s,y+s,z+s},{x+s,y+s,z+s},{x-s,y+s,z+s},{x-s,y-s,z+s}},
        // back
        {{x-s,y-s,z-s},{x-s,y+s,z-s},{x+s,y+s,z-s},{x+s,y+s,z-s},{x+s,y-s,z-s},{x-s,y-s,z-s}},
        // left
        {{x-s,y+s,z+s},{x-s,y+s,z-s},{x-s,y-s,z-s},{x-s,y-s,z-s},{x-s,y-s,z+s},{x-s,y+s,z+s}},
        // right
        {{x+s,y+s,z+s},{x+s,y-s,z-s},{x+s,y+s,z-s},{x+s,y-s,z-s},{x+s,y+s,z+s},{x+s,y-s,z+s}},
        // top
        {{x-s,y+s,z-s},{x-s,y+s,z+s},{x+s,y+s,z+s},{x+s,y+s,z+s},{x+s,y+s,z-s},{x-s,y+s,z-s}},
        // bottom
        {{x-s,y-s,z-s},{x+s,y-s,z-s},{x+s,y-s,z+s},{x+s,y-s,z+s},{x-s,y-s,z+s},{x-s,y-s,z-s}}
    };

    for(int f=0; f<6; f++){
        glm::vec3 c = faceColors[f];
        for(int v=0; v<6; v++){
            positions.push_back(faceVertices[f][v][0]);
            positions.push_back(faceVertices[f][v][1]);
            positions.push_back(faceVertices[f][v][2]);

            colors.push_back(c.r);
            colors.push_back(c.g);
            colors.push_back(c.b);
        }
    }
};
