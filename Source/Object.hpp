//
//  Object.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/23/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <fstream>
#include <vector>

#include <GL/glut.h>

#include "Point.hpp"

using namespace std;

class Object {
public:
    GLfloat angle = 0; // rotate angle, use for drawScreen
    GLfloat sScale = 1;
    static vector<Object*> objects;
    static Object* constructObject(int type);
    virtual void draw() = 0;
    virtual void drawScreen() = 0;
};

#endif /* Object_hpp */
