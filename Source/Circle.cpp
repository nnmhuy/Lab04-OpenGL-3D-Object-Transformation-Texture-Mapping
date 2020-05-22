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
    draw();
}

void Circle::circleSymmetric8(GLint x, GLint y) {
    // glVertex2i(x + center.x, y + center.y);
    // glVertex2i(y + center.x, x + center.y);
    // glVertex2i(x + center.x, -y + center.y);
    // glVertex2i(y + center.x, -x + center.y);
    // glVertex2i(-x + center.x, y + center.y);
    // glVertex2i(-y + center.x, x + center.y);
    // glVertex2i(-x + center.x, -y + center.y);
    // glVertex2i(-y + center.x, -x + center.y);
    // store to base_points
    base_points.push_back(Point(x + center.x, y + center.y));
    base_points.push_back(Point(y + center.x, x + center.y));
    base_points.push_back(Point(x + center.x, -y + center.y));
    base_points.push_back(Point(y + center.x, -x + center.y));
    base_points.push_back(Point(-x + center.x, y + center.y));
    base_points.push_back(Point(-y + center.x, x + center.y));
    base_points.push_back(Point(-x + center.x, -y + center.y));
    base_points.push_back(Point(-y + center.x, -x + center.y));
}


void Circle::draw() {
    cout << "Drawing circle" << endl;

    GLfloat p = 1 - radius;
    GLint x = 0;
    GLint y = radius;
    
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
}


void Circle::drawScreen() {
    glColor3f(1.0f, 1.0f, 1.0f);
    
    glBegin(GL_POINTS); // Select points as the primitive
        // draw from stored based points
        for (int i = 0; i < (int)base_points.size(); ++i) {
            glVertex2i(base_points[i].x, base_points[i].y);
        }
    glEnd(); // Done drawing points
}

void Circle::scale(double dx, double dy) {
    radius = radius * dx;
    base_points.clear();
    draw();
}


bool Circle::isPointInside(Point point) {
    // check distance to center less or equal radius
    return ((point.x - center.x) * (point.x - center.x) + (point.y - center.y) * (point.y - center.y)) <= radius * radius;
}
