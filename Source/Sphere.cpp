//
//  Sphere.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include <math.h>
#include "Sphere.hpp"

Sphere::Sphere(double radius, int nStack, int nSector) {
    this->radius = radius;
    this->nStack = nStack;
    this->nSector = nSector;
}

void Sphere::draw() {
}


void Sphere::drawScreen() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(-1.0f, 1.0f, -7.0f); // Move into the screen
    glScalef(0.5f, 0.5f, 0.5f);
    glRotatef(angle, 1.0f, 1.0f, 1.0f); // Rotate about (1,1,1)-axis


    for (int i = 0; i < nStack; ++i) {
        double latitude1 = (PI / nStack) * i - PI / 2.0;
        double latitude2 = (PI / nStack) * (i + 1) - PI / 2.0;
        double sinLat1 = sin(latitude1);
        double cosLat1 = cos(latitude1);
        double sinLat2 = sin(latitude2);
        double cosLat2 = cos(latitude2);
        glBegin(GL_QUAD_STRIP);
            for (int j = 0; j <= nSector; ++j) {
                double longitude = (2 * PI / nSector) * j;
                double sinLong = sin(longitude);
                double cosLong = cos(longitude);
                double x1 = cosLong * cosLat1;
                double y1 = sinLong * cosLat1;
                double z1 = sinLat1;
                double x2 = cosLong * cosLat2;
                double y2 = sinLong * cosLat2;
                double z2 = sinLat2;

                glNormal3d(x2, y2, z2);
                glTexCoord2d(1.0 / nSector * j, 1.0 / nStack * (i + 1));
                glVertex3d(radius * x2, radius * y2, radius * z2);

                glNormal3d(x1, y1, z1);
                glTexCoord2d(1.0 / nSector * j, 1.0 / nStack * i);
                glVertex3d(radius * x1, radius * y1, radius * z1);
            }
        glEnd();
    }
}