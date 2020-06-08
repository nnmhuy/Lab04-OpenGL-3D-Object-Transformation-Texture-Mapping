//
//  Object.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/23/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include <stdlib.h> /* srand, rand */
#include "Object.hpp"
#include "Sphere.hpp"
#include "Cube.hpp"
#include "Cylinder.hpp"
#include "Cone.hpp"
#include "Disk.hpp"
#include "Torus.hpp"
#include "Hyperboloid.hpp"
#include "Paraboloid.hpp"

Object::Object(int textureIndex) {
    this->textureIndex = textureIndex;
}

Object* Object::constructObject(int type) {
    int textureIndex = type;
    switch (type) {
        case 0:
            return new Sphere(textureIndex);
        case 1:
            return new Cube(textureIndex);
        case 2:
            return new Cylinder(textureIndex);
        case 3:
            return new Cone(textureIndex);
        case 4:
            return new Disk(textureIndex);
        case 5:
            return new Torus(textureIndex);
        case 6:
            return new Hyperboloid(textureIndex);
        case 7:
            return new Paraboloid(textureIndex);
        default:
            return NULL;
    }
    return NULL;
}