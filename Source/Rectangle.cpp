//
//  Rectangle.cpp
//  Lab02_Object_Coloring
//
//  Created by Huy Nguyen Ngoc Minh on 5/2/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Rectangle.hpp"

void Rectangle::getParameters(Point start_point, Point end_point){
    top_left = start_point;
    bottom_right = end_point;
    if (top_left.x > bottom_right.x) swap(top_left.x, bottom_right.x);
    if (top_left.y < bottom_right.y) swap(top_left.y, bottom_right.y);
    center.x = (top_left.x + bottom_right.x) / 2;
    center.y = (top_left.y + bottom_right.y) / 2;
    draw();
}

void Rectangle::draw() {
    cout << "Drawing rectangle" << endl;
    base_points.push_back(Point(top_left.x, top_left.y));
    base_points.push_back(Point(bottom_right.x, top_left.y));
    base_points.push_back(Point(bottom_right.x, bottom_right.y));
    base_points.push_back(Point(top_left.x, bottom_right.y));
}


void Rectangle::drawScreen() {
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