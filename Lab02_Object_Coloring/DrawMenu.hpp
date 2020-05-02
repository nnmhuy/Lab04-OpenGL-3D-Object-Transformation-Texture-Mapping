//
//  DrawMenu.hpp
//  Lab02_Object_Coloring
//
//  Created by Huy Nguyen Ngoc Minh on 5/2/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#ifndef DrawMenu_hpp
#define DrawMenu_hpp

#include <stdio.h>
#include <iostream>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>

#include "Point.hpp"
#include "Object.hpp"
#include "Polygon.hpp"

using namespace std;

class DrawMenu {
public:
    static Point start_point, end_point;
    static int shape;
    static void getStartPoint(int button, int state, int x, int y); // left click down
    static void getEndPoint(int button, int state, int x, int y); // left click up
    static void startDrawing();
    static void handleToggleMenu(int shape);
};

#endif /* DrawMenu_hpp */
