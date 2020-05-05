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
#include "Polygon.hpp"

Object* Object::constructObject(int type) {
    switch (type) {
        case 1:
            return new EllipseMidpoint();
            break;
        case 2:
            return new Rectangle();
            break;
        case 3:
            return new Polygon();
        default:
            return NULL;
    }
    return NULL;
}
