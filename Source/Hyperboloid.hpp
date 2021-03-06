//
//  HyperboloidMidpoint.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef Hyperboloid_hpp
#define Hyperboloid_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Object.hpp"
#include "Point.hpp"

class Hyperboloid: public Object {
    double a = 1, b = 1, c = 1;
    double height = 1;
    int nSlice = 50, nStack = 50;
    Point center;
public:
    Hyperboloid() = default;
    Hyperboloid(int textureIndex);
    Hyperboloid(double a, double b, double c, double height, int nSlice, int nStack);
    void draw() override;
    void drawScreen() override;
};

#endif /* Hyperboloid_hpp */
