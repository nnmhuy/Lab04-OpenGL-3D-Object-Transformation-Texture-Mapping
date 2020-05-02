//
//  ColorMenu.hpp
//  Lab02_Object_Coloring
//
//  Created by Huy Nguyen Ngoc Minh on 5/2/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#ifndef ColorMenu_hpp
#define ColorMenu_hpp

#include <stdio.h>
#include <iostream>
#include <queue>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>

#include "Config.hpp"
#include "Point.hpp"
#include "RGBColor.hpp"

using namespace std;


class ColorMenu {
public:
    static Point p;
    static int currentColor;
    static void getMouseClickPosition(int button, int state, int x, int y);
    static void handleToggleMenu(int num);
    static void executeColor();
    static RGBColor getPixel(Point &p);
    static void putPixel(Point &p, RGBColor &color);
};

#endif /* ColorMenu_hpp */
