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
    GLint x, y, z;
    friend ifstream &operator >> (ifstream &input, Point &point);
    Point() = default;
    Point(GLint x, GLint y);
    void translate(int dx, int dy); // translate in x and translate in y
    void scale(double sx, double sy); // scale in x and scale in y
    void rotate(Point center, int alpha); // in degree
};
#endif /* Point_hpp */
