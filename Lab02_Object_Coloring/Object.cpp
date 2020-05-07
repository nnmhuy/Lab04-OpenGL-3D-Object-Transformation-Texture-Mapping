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
        case 4:
            return new Star();
        default:
            return NULL;
    }
    return NULL;
}
