//
//  DiskMidpoint.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef Disk_hpp
#define Disk_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Object.hpp"
#include "Point.hpp"

class Disk: public Object {
    double radius = 1;
    int nSlice = 50, nRing = 50;
    Point center;
public:
    Disk() = default;
    Disk(int textureIndex);
    Disk(double radius, int nSlice, int nRing);
    void draw() override;
    void drawScreen() override;
};

#endif /* Disk_hpp */
