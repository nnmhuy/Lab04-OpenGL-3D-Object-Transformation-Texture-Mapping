//
//  RegularPentagon.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef RegularPentagon_hpp
#define RegularPentagon_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Object.hpp"
#include "Point.hpp"

#define PI 3.14159265

class RegularPentagon: public Object {
    Point center;
    GLint radius;
    
public:
    void getParameters(Point start_point, Point end_point) override;
    void draw() override;
};

#endif /* RegularPentagon_hpp */
