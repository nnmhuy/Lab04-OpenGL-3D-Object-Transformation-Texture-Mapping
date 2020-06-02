//
//  Point.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/23/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include <math.h>
#include "Point.hpp"

#define PI 3.14159265

Point::Point(GLfloat x, GLfloat y, GLfloat z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

ifstream& operator >> (ifstream &input, Point &point)
{
    input >> point.x;
    input >> point.y;
    point.z = 1;
    return input;
}