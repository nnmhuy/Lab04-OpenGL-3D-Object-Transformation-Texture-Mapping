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
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/GLUT.h>
#include "Point.hpp"

using namespace std;

class Object {
public:
    static Object* constructObject(int type);
    virtual void getParameters(Point start_point, Point end_point) = 0;
    virtual void draw() = 0;
};

#endif /* Object_hpp */
