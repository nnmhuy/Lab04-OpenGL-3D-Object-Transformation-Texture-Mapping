//
//  Polygon.cpp
//  Lab02_Object_Coloring
//
//  Created by Huy Nguyen Ngoc Minh on 5/2/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Polygon.hpp"

void Polygon::getParameters(Point start_point, Point end_point) {
    cout << "Drawing polygon" << endl;
    glutDetachMenu(GLUT_RIGHT_BUTTON);
    glutMouseFunc(handleInsertPoint);
}

void Polygon::handleInsertPoint(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        currentPoints.push_back(Point(x, y));
        int n = (int) currentPoints.size();
        if (n > 1) {
            glColor3f(1.0f, 1.0f, 1.0f);
            glBegin(GL_LINES); // Select line as the primitive
                glVertex2i(currentPoints[n - 2].x, currentPoints[n - 2].y);
                glVertex2i(x, y);
            glEnd(); // Done drawing line
            glFlush();
        }
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) { // end drawing polygon
        currentPoints.push_back(Point(x, y));
        int n = (int) currentPoints.size();
        if (n > 1) {
            glColor3f(1.0f, 1.0f, 1.0f);
            glBegin(GL_LINES); // Select line as the primitive
                glVertex2i(currentPoints[n - 2].x, currentPoints[n - 2].y);
                glVertex2i(x, y);
                glVertex2i(x, y);
                glVertex2i(currentPoints[0].x, currentPoints[0].y);
            glEnd(); // Done drawing line
            glFlush();
        }
        glutMouseFunc(NULL);
        glutSetMenu(Config::main_menu_id);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    }
}

void Polygon::draw() {
    
}
