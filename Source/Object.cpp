//
//  Object.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/23/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Object.hpp"
#include "Sphere.hpp"
#include "Cube.hpp"
#include "Cylinder.hpp"
#include "Cone.hpp"
#include "Disk.hpp"

Object* Object::constructObject(int type) {
    switch (type) {
        case 0:
            return new Sphere();
        case 1:
            return new Cube();
            break;
        case 2:
            return new Cylinder();
        case 3:
            return new Cone();
        case 4:
            return new Disk();
        // case 5:
        //     return new RegularPentagon();
        // case 6:
        //     return new RegularHexagon();
        default:
            return NULL;
    }
    return NULL;
}