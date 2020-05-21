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
}

void Rectangle::draw() {
    cout << "Drawing rectangle" << endl;
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_LINE_LOOP); // Select points as the primitive
        glVertex2i(top_left.x, top_left.y);
        glVertex2i(bottom_right.x, top_left.y);
        glVertex2i(bottom_right.x, bottom_right.y);
        glVertex2i(top_left.x, bottom_right.y);
    glEnd(); // Done drawing points
}
