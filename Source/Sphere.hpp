//
//  SphereMidpoint.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef Sphere_hpp
#define Sphere_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Object.hpp"
#include "Point.hpp"

class Sphere: public Object {
    double radius = 1;
    int nStack = 50, nSector = 50;
    Point center;
public:
    Sphere() = default;
    Sphere(int textureIndex);
    Sphere(double radius, int nStack, int nSector);
    void draw() override;
    void drawScreen() override;
};

#endif /* Sphere_hpp */
