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
    glutMouseFunc(handleInsertPoint);
}

void Polygon::handleInsertPoint(int button, int state, int x, int y) {
    glutDetachMenu(GLUT_RIGHT_BUTTON);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        drawingPolygon->base_points.push_back(Point(x, y));
        int n = (int) drawingPolygon->base_points.size();
        if (n == 1) {
        // initialize top_left and bottom_right
            top_left.x = bottom_right.x = x;
            top_left.y = bottom_right.y = y;
        }
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) { // end drawing polygon
        drawingPolygon->base_points.push_back(Point(x, y));
        glutMouseFunc(NULL);
        glutSetMenu(Config::main_menu_id);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        drawingPolygon->draw();
    }

    // update top_left and bottom_right
    top_left.x = min(top_left.x, x);
    top_left.y = max(top_left.y, y);
    bottom_right.x = max(bottom_right.x, x);
    bottom_right.y = min(bottom_right.y, y);

    glutPostRedisplay();
}

void Polygon::draw() {
    center.x = (top_left.x + bottom_right.x) / 2;
    center.y = (top_left.y + bottom_right.y) / 2;
}

void Polygon::drawScreen() {
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_LINE_LOOP); // Select line loop as the primitive
        for (int i = 0; i < (int)base_points.size(); ++i){
            // glVertex2i(base_points[i].x, base_points[i].y);
            Point p = base_points[i];
            p.rotate(center, alpha);
            p.scale(center, sScale, sScale);
            glVertex2i(p.x, p.y);
        }
    glEnd(); // Done drawing points
}
