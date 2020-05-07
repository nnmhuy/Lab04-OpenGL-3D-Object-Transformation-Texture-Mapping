//
//  Circle.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Circle.hpp"

void Circle::getParameters(Point start_point, Point end_point){
    radius = min(abs(start_point.x - end_point.x), abs(start_point.y - end_point.y)) / 2;
    int signX = (end_point.x - start_point.x) / abs(end_point.x - start_point.x);
    int signY = (end_point.y - start_point.y) / abs(end_point.y - start_point.y);
    center.x = start_point.x + signX * radius;
    center.y = start_point.y + signY * radius;
}

void Circle::circleSymmetric8(GLint x, GLint y) {
    glVertex2i(x + center.x, y + center.y);
    glVertex2i(y + center.x, x + center.y);
    glVertex2i(x + center.x, -y + center.y);
    glVertex2i(y + center.x, -x + center.y);
    glVertex2i(-x + center.x, y + center.y);
    glVertex2i(-y + center.x, x + center.y);
    glVertex2i(-x + center.x, -y + center.y);
    glVertex2i(-y + center.x, -x + center.y);
}


void Circle::draw() {
    glColor3f(1.0f, 1.0f, 1.0f);
    
    GLfloat p = 1 - radius;
    GLint x = 0;
    GLint y = radius;
    
    glBegin(GL_POINTS); // Select points as the primitive
        while (x <= y) {
            circleSymmetric8(x, y);
            if (p < 0) {
                p = p + 2 * (x + 1) + 1;
            } else {
                y = y - 1;
                p = p + 2 * (x + 1) + 1 - 2 * y;
            }
            x += 1;
        }
    glEnd(); // Done drawing points
}
