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

#include <GL/glut.h>

using namespace std;

class Point {
public:
    GLfloat x, y, z;
    friend ifstream &operator >> (ifstream &input, Point &point);
    Point() = default;
    Point(GLfloat x, GLfloat y, GLfloat z);
};
#endif /* Point_hpp */
