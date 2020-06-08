//
//  Disk.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Disk.hpp"

Disk::Disk(double radius, int nSlice, int nRing) {
    this->radius = radius;
    this->nSlice = nSlice;
    this->nRing = nRing;
}

void Disk::draw() {

}


void Disk::drawScreen() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(-3.0f, -1.0f, -7.0f); // Move right and into the screen
    glScalef(0.5f, 0.5f, 0.5f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);


    glColor3f(1.0f, 1.0f, 1.0f);

    // draw upper face disk
    glNormal3d(0, 0, 1);
    for (int i = 0; i < nRing; ++i) {
        double radius1 = ((double)i / nRing) * radius;
        double radius2 = ((double)(i + 1) / nRing) * radius;

        glBegin(GL_QUAD_STRIP);
            for (int i = 0; i <= nSlice; ++i) {
                double theta = (2 * PI) / nSlice * i;
                double sinTheta = sin(theta);
                double cosTheta = cos(theta);

                double x = cosTheta;
                double y = sinTheta;

                glNormal3d(0, 0, -1);
                //glTexCoord2d(0.5 * (1 + x * radius1), 0.5 * (1 + y * radius1));
                glVertex3f(radius1 * x, radius1 * y, 0);

                //glTexCoord2d(0.5 * (1 + x * radius2), 0.5 * (1 + y * radius2));
                glVertex3f(radius2 * x, radius2 * y, 0);
                
            }
        glEnd();
    }
}