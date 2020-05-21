//
//  RGBColor.hpp
//  Lab02_Object_Coloring
//
//  Created by Huy Nguyen Ngoc Minh on 5/2/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef RGBColor_hpp
#define RGBColor_hpp

#include <stdio.h>

class RGBColor {
public:
    float red, green, blue;
    RGBColor(float r, float g, float b);
    bool operator==(const RGBColor& b);
};

#endif /* RGBColor_hpp */
