//
//  ParaboloidMidpoint.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef Paraboloid_hpp
#define Paraboloid_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Object.hpp"
#include "Point.hpp"

class Paraboloid: public Object {
    double a = 1, b = 1;
    double height = 1;
    int nSlice = 50, nStack = 50;
    Point center;
public:
    Paraboloid() = default;
    Paraboloid(int textureIndex);
    Paraboloid(double a, double b, double height, int nSlice, int nStack);
    void draw() override;
    void drawScreen() override;
};

#endif /* Paraboloid_hpp */
