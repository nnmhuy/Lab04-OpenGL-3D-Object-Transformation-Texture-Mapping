//
//  ConeMidpoint.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef Cone_hpp
#define Cone_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Object.hpp"
#include "Point.hpp"

class Cone: public Object {
    double radius = 1;
    double height = 2;
    int nSlice = 50, nStack = 50;
    Point center;
public:
    Cone() = default;
    Cone(int textureIndex);
    Cone(int radius, int height, int nSlice, int nStack);
    void draw() override;
    void drawScreen() override;
};

#endif /* Cone_hpp */
