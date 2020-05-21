//
//  RGBColor.cpp
//  Lab02_Object_Coloring
//
//  Created by Huy Nguyen Ngoc Minh on 5/2/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "RGBColor.hpp"


RGBColor::RGBColor(float r, float g, float b) {
    red = r;
    green = g;
    blue = b;
}

bool RGBColor::operator==(const RGBColor& b) {
    return (red == b.red) && (green == b.green) && (blue == b.blue);
}
