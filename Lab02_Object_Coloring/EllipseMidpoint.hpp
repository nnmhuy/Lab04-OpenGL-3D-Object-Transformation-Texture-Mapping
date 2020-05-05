//
//  EllipseMidpoint.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef EllipseMidpoint_hpp
#define EllipseMidpoint_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Object.hpp"
#include "Point.hpp"

class EllipseMidpoint: public Object {
    Point center;
    GLdouble rx, ry;
public:
    void getParameters(Point start_point, Point end_point) override;
    void draw() override;
    void ellipseSymmetric4(GLint x, GLint y);
};

#endif /* EllipseMidpoint_hpp */
