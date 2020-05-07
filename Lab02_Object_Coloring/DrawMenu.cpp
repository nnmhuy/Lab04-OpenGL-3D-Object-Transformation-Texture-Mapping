//
//  DrawMenu.cpp
//  Lab02_Object_Coloring
//
//  Created by Huy Nguyen Ngoc Minh on 5/2/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "DrawMenu.hpp"


void DrawMenu::getStartPoint(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glutMouseFunc(getEndPoint);
        cout << "Shape start point: " << x << " " << y << endl;
        DrawMenu::start_point = Point(x, y);
    } else {
        if (button != GLUT_LEFT_BUTTON) {
            glutMouseFunc(NULL);
            cout << "Cancelled" << endl;
        }
    }
}

void DrawMenu::getEndPoint(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        glutMouseFunc(NULL);
        cout << "Shape end point: " << x << " " << y << endl;
        DrawMenu::end_point = Point(x, y);
        startDrawing();
    } else {
        glutMouseFunc(NULL);
        cout << "Cancelled" << endl;
    }
}

void DrawMenu::startDrawing() {
    int width, height;
    width = glutGet(GLUT_WINDOW_WIDTH);
    height = glutGet(GLUT_WINDOW_HEIGHT);
    cout << " Window size: " << width << " " << height << endl;
    
    int* p = new int[4];
    glGetIntegerv(GL_VIEWPORT, p);
    cout << "Viewport: " << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << endl;
    delete [] p;
    
    Object * object = Object::constructObject(DrawMenu::shape);
    object->getParameters(DrawMenu::start_point, DrawMenu::end_point);
    object->draw();
    glFlush();
}

void DrawMenu::handleToggleMenu(int shape){
    cout << "DRAW MENU" << endl;
    DrawMenu::shape = shape;
    
    if (shape == 0) {
        Polygon polygon;
        polygon.getParameters(Point(0, 0), Point(0, 0));
        polygon.points = Polygon::currentPoints;
        Polygon::currentPoints.clear();
    } else {
        glutMouseFunc(getStartPoint);
    }

//    glutPostRedisplay();
}
