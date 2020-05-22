//
//  AffineTransformMenu.hpp
//  Lab02_Object_Coloring
//
//  Created by Huy Nguyen Ngoc Minh on 5/2/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#ifndef AffineTransformMenu_hpp
#define AffineTransformMenu_hpp

#include <stdio.h>
#include <iostream>
#include <queue>

#include <GL/glut.h>

#include "Config.hpp"
#include "Point.hpp"
#include "RGBColor.hpp"

using namespace std;


class AffineTransformMenu {
public:
    static Point p;
    static int currentObjectIndex;
    static void getMouseClickPosition(int button, int state, int x, int y);
    static void handleToggleMenu(int num);
    static void mapKeyboardToFunctions(int key, int x, int y);
    static int getObjectIndex(Point p);
};

#endif /* AffineTransformMenu_hpp */
