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

Point::Point(GLint x, GLint y) {
    this->x = x;
    this->y = y;
    this->z = 1;
}

ifstream& operator >> (ifstream &input, Point &point)
{
    input >> point.x;
    input >> point.y;
    point.z = 1;
    return input;
}

void Point::translate(int dx, int dy) {
    x += dx;
    y += dy;
}

void Point::scale(double sx, double sy) {
    x = round(sx * x);
    y = round(sy * y);
}

void Point::rotate(Point center, int alpha) {
    double cosAlpha =  cos(double(alpha) * PI / 180.0);
    double sinAlpha =  sin(double(alpha) * PI / 180.0);

    x -= center.x;
    y -= center.y;
    
    int newX = round(cosAlpha * x - sinAlpha * y);
    int newY = round(sinAlpha * x + cosAlpha * y);
    
    x = newX + center.x;
    y = newY + center.y;
}


