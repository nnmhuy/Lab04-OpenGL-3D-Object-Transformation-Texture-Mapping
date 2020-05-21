//
//  RegularHexagon.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef RegularHexagon_hpp
#define RegularHexagon_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Object.hpp"
#include "Point.hpp"

#define PI 3.14159265

class RegularHexagon: public Object {
    Point center;
    GLint radius;
    
public:
    void getParameters(Point start_point, Point end_point) override;
    void draw() override;
};

#endif /* RegularHexagon_hpp */
