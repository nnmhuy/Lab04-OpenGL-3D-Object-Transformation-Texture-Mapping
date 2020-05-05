//
//  Point.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/23/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <fstream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/GLUT.h>

using namespace std;

class Point {
public:
    GLint x, y;
    friend ifstream &operator >> (ifstream &input, Point &point);
    Point() = default;
    Point(GLint x, GLint y);
};
#endif /* Point_hpp */
