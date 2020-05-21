//
//  RegularPentagon.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "RegularPentagon.hpp"

void RegularPentagon::getParameters(Point start_point, Point end_point){
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

void RegularPentagon::draw() {
    glColor3f(1.0f, 1.0f, 1.0f);
    
    float cos72 =  cos(72.0 * PI / 180.0);
    float sin72 =  sin(72.0 * PI / 180.0);

    Point points[5];
    points[0] = Point(0, -radius);
    for (int i = 1; i < 5; ++i) {
        points[i] = Point(points[i - 1].x * cos72 - points[i - 1].y * sin72, points[i - 1].y * cos72 + points[i - 1].x * sin72);
    }
    
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 5; ++i) {
            glVertex2i(center.x + points[i].x, center.y + points[i].y);
        }
    glEnd(); // Done drawing points
}
