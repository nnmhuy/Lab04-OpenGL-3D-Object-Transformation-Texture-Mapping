//
//  EllipseMidpoint.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "EllipseMidpoint.hpp"

void EllipseMidpoint::getParameters(Point start_point, Point end_point){
    center.x = (start_point.x + end_point.x) / 2;
    center.y = (start_point.y + end_point.y) / 2;
    rx = abs(start_point.x - end_point.x) / 2;
    ry = abs(start_point.y - end_point.y) / 2;
}

void EllipseMidpoint::ellipseSymmetric4(GLint x, GLint y) {
    glVertex2i(x + center.x, y + center.y);
    glVertex2i(x + center.x, -y + center.y);
    glVertex2i(-x + center.x, y + center.y);
    glVertex2i(-x + center.x, -y + center.y);
}


void EllipseMidpoint::draw() {
    glColor3f(1.0f, 1.0f, 1.0f);
    cout << "Drawing ellipse" << endl;
    
    bool isSwap = false;
    if (ry > rx) {
        swap(rx, ry);
        isSwap = true;
    }
    
    GLdouble p = ry*ry + 0.25*rx*rx - rx*rx*ry;
    
    GLdouble x = 0;
    GLdouble y = ry;
    GLdouble dx = 2*ry*ry*x;
    GLdouble dy = 2*rx*rx*y;
    
    
    glBegin(GL_POINTS); // Select points as the primitive
        while (dx < dy) {
            if (!isSwap) {
                ellipseSymmetric4(x, y);
            } else {
                ellipseSymmetric4(y, x);
            }
            if (p < 0) {
                x = x + 1;
                dx = 2*ry*ry*x;
                p = p + dx + ry*ry;
            } else {
                x = x + 1;
                y = y - 1;
                dx = 2*ry*ry*x;
                dy = 2*rx*rx*y;
                p = p + dx - dy + ry*ry;
            }
        }
    
        p = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
        dx = 2*ry*ry*x;
        dy = 2*rx*rx*y;
        while (y >= 0) {
            if (!isSwap) {
                ellipseSymmetric4(x, y);
            } else {
                ellipseSymmetric4(y, x);
            }
            if (p > 0) {
                y = y - 1;
                dy = 2*rx*rx*y;
                p = p + rx*rx - dy;
            } else {
                y = y - 1;
                x = x + 1;
                dx = 2*ry*ry*x;
                dy = 2*rx*rx*y;
                p = p + dx - dy + rx*rx;
            }
        }
    glEnd(); // Done drawing points
    
    if (isSwap) {
        swap(rx, ry);
    }
}
