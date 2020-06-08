//
//  TorusMidpoint.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef Torus_hpp
#define Torus_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Object.hpp"
#include "Point.hpp"

class Torus: public Object {
    double innerRadius = 0.5, outterRadius = 1;
    int nSlice = 50, nRing = 50;
    Point center;
public:
    Torus() = default;
    Torus(double innerRadius, double outterRadius, int nSlice, int nRing);
    void draw() override;
    void drawScreen() override;
};

#endif /* Torus_hpp */
