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
#include "Torus.hpp"
#include "Hyperboloid.hpp"
#include "Paraboloid.hpp"

Object* Object::constructObject(int type) {
    switch (type) {
        case 0:
            return new Sphere();
        case 1:
            return new Cube();
        case 2:
            return new Cylinder();
        case 3:
            return new Cone();
        case 4:
            return new Disk();
        case 5:
            return new Torus();
        case 6:
            return new Hyperboloid();
        case 7:
            return new Paraboloid();
        default:
            return NULL;
    }
    return NULL;
}