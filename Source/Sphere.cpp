//
//  Sphere.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Sphere.hpp"

void Sphere::draw() {
    cout << "Drawing Sphere" << endl;
    
    //shpere
}


void Sphere::drawScreen() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(0.0f, 2.0f, -7.0f); // Move right and into the screen
    glScalef(0.5f, 0.5f, 0.5f);

    glutSolidSphere(1, 25, 25);
}