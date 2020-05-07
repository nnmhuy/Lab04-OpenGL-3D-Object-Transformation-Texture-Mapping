//
//  ColorMenu.cpp
//  Lab02_Object_Coloring
//
//  Created by Huy Nguyen Ngoc Minh on 5/2/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "ColorMenu.hpp"

const RGBColor colorsTable[3] = {
    RGBColor(1, 0, 0), // red
    RGBColor(0, 1, 0), // green
    RGBColor(0, 0, 1)  // blue
};

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

float * Ptr;

void ColorMenu::getMouseClickPosition(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glutMouseFunc(NULL);
        cout << "Color from point: " << x << " " << y << endl;
        ColorMenu::p = Point(x, y);
        executeColor();
    } else {
        if (button != GLUT_LEFT_BUTTON) {
            glutMouseFunc(NULL);
            cout << "Cancelled color" << endl;
        }
    }
}

void ColorMenu::handleToggleMenu(int color){
    cout << "COLOR MENU" << endl;
    
    // 0: red, 1: green, 2: blue
    ColorMenu::currentColor = color - 1;
    glutMouseFunc(getMouseClickPosition);

}

void ColorMenu::executeColor() {
    Ptr = new float [3 * (Config::MAX_COORDINATE + 1) *(Config::MAX_COORDINATE + 1)];
    glReadPixels(0, 0, Config::MAX_COORDINATE, Config::MAX_COORDINATE, GL_RGB, GL_FLOAT, Ptr);
    RGBColor oldColor = getPixel(p);
    RGBColor newColor = colorsTable[currentColor];
    
    queue <Point> que;
    putPixel(p, newColor);
    que.push(p);
    while (!que.empty()) {
        Point f = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i) {
            Point F;
            F.x = f.x + dx[i];
            F.y = f.y + dy[i];
            if (F.x < 0 || F.x > Config::MAX_COORDINATE || F.y < 0 || F.y > Config::MAX_COORDINATE) continue;

            if (getPixel(F) == oldColor) {
                putPixel(F, newColor);
                que.push(F);
            }
        }
    }
    glFlush();
    delete []Ptr;
}

RGBColor ColorMenu::getPixel(Point &p) {
//    int d = ((Config::MAX_COORDINATE - p.y) * Config::MAX_COORDINATE + p.x ) * 3;
    int d = ((Config::MAX_COORDINATE - p.y) * Config::MAX_COORDINATE + p.x ) * 3;
    return RGBColor(Ptr[d], Ptr[d + 1], Ptr[d + 2]);
}

void ColorMenu::putPixel(Point &p, RGBColor &color) {
    float * ptr = new float [3];
    ptr[0] = color.red;
    ptr[1] = color.green;
    ptr[2] = color.blue;
    
    int d = ((Config::MAX_COORDINATE - p.y) * Config::MAX_COORDINATE + p.x ) * 3;
    Ptr[d] = color.red;
    Ptr[d + 1] = color.green;
    Ptr[d + 2] = color.blue;
    
    glRasterPos2i(p.x, p.y);
    glDrawPixels(1, 1, GL_RGB, GL_FLOAT, ptr);
    delete [] ptr;
}
