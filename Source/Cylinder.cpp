//
//  Cylinder.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Cylinder.hpp"

void Cylinder::draw() {
    cout << "Drawing Cylinder" << endl;
    
    //shpere
}


void Cylinder::drawScreen() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(2.0f, 2.0f, -7.0f); // Move right and into the screen
    glScalef(0.5f, 0.5f, 0.5f);

    GLUquadric *quad = gluNewQuadric();

    gluCylinder(quad,
                1,
                1,
                2,
                50,
                50);
    gluDeleteQuadric(quad);
}