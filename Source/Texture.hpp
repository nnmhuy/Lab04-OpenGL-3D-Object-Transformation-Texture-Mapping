#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <GL/glut.h>
#include <SOIL/SOIL.h>

using namespace std;

class Texture {
public:
    static vector<GLuint> textureList;
    static bool loadTexture();
};

#endif /* Texture_hpp */
