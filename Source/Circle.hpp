//
//  CircleMidpoint.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Object.hpp"
#include "Point.hpp"

class Circle: public Object {
    Point center;
    GLint radius;
    
public:
    void getParameters(Point start_point, Point end_point) override;
    void draw() override;
    void circleSymmetric8(GLint x, GLint y);
};

#endif /* Circle_hpp */
