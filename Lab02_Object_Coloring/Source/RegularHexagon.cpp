//
//  RegularHexagon.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "RegularHexagon.hpp"

void RegularHexagon::getParameters(Point start_point, Point end_point){
    radius = min(abs(start_point.x - end_point.x), abs(start_point.y - end_point.y)) / 2;
    int difference = (abs(start_point.x - end_point.x) - abs(start_point.y - end_point.y)) / 2;
    center.x = (start_point.x + end_point.x) / 2;
    center.y = (start_point.y + end_point.y) / 2;
    if (difference > 0) {
        center.x -= difference;
    } else {
        center.y -= difference;
    }
}

void RegularHexagon::draw() {
    glColor3f(1.0f, 1.0f, 1.0f);
    
    float cos60 =  cos(60.0 * PI / 180.0);
    float sin60 =  sin(60.0 * PI / 180.0);

    Point points[6];
    points[0] = Point(0, -radius);
    for (int i = 1; i < 6; ++i) {
        points[i] = Point(points[i - 1].x * cos60 - points[i - 1].y * sin60, points[i - 1].y * cos60 + points[i - 1].x * sin60);
    }
    
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 6; ++i) {
            glVertex2i(center.x + points[i].x, center.y + points[i].y);
        }
    glEnd(); // Done drawing points
}
