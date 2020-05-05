//
//  Point.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/23/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Point.hpp"

Point::Point(GLint x, GLint y) {
    this->x = x;
    this->y = y;
}

ifstream& operator >> (ifstream &input, Point &point)
{
    input >> point.x;
    input >> point.y;

    return input;
}
