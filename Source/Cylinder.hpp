//
//  CylinderMidpoint.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef Cylinder_hpp
#define Cylinder_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Object.hpp"
#include "Point.hpp"

class Cylinder: public Object {
    double radius = 1;
    double height = 2;
    int nSlice = 50, nStack = 50;
    Point center;
public:
    Cylinder() = default;
    Cylinder(int radius, int height, int nSlice, int nStack);
    void draw() override;
    void drawScreen() override;
};

#endif /* Cylinder_hpp */
