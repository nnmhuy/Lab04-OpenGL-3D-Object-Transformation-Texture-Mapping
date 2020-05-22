//
//  Object.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/23/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Object.hpp"
#include "EllipseMidpoint.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Star.hpp"
#include "Polygon.hpp"
#include "RegularPentagon.hpp"
#include "RegularHexagon.hpp"

Object* Object::constructObject(int type) {
    switch (type) {
        case 0:
            return new Polygon();
        case 1:
            return new EllipseMidpoint();
            break;
        case 2:
            return new Rectangle();
        case 3:
            return new Circle();
        // case 4:
        //     return new Star();
        // case 5:
        //     return new RegularPentagon();
        // case 6:
        //     return new RegularHexagon();
        default:
            return NULL;
    }
    return NULL;
}

int Object::getClickedObjectIndex(Point p) {
    int n = Object::objects.size();
    for (int i = n - 1; i >= 0; --i) {
        if (Object::objects[i]->isPointInside(p)) return i;
    }
    return -1;
}


void Object::translate(int dx, int dy) {
    center.translate(dx, dy);
    for (int i = 0; i < (int)base_points.size(); ++i) {
        base_points[i].translate(dx, dy);
    }
}

void Object::scale(double sx, double sy) {
    for (int i = 0; i < (int)base_points.size(); ++i) {
        base_points[i].scale(sx, sy);
    }
}

void Object::rotate(int alpha) {
    for (int i = 0; i < (int)base_points.size(); ++i) {
        base_points[i].rotate(center, alpha);
    }
}

bool Object::isPointInside(Point point) {
    cout << "Object::isPointInside" << endl;
    bool isInside = false;
    int n = base_points.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        if ((base_points[i].y > point.y) != (base_points[j].y > point.y)
            && (point.x < 
                (base_points[j].x - base_points[i].x) * (point.y - base_points[i].y) 
                / (base_points[j].y - base_points[i].y) + base_points[i].x)) {
                isInside = !isInside;
            }
    }
    return isInside;
}