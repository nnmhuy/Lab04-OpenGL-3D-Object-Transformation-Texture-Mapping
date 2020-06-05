//
//  Cone.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Cone.hpp"

Cone::Cone(int radius, int height, int nSlice, int nStack) {
    this->radius = radius;
    this->height = height;
    this->nSlice = nSlice;
    this->nStack = nStack;
}

void Cone::draw() {

}


void Cone::drawScreen() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(-2.0f, -2.0f, -7.0f); // Move right and into the screen
    glScalef(0.5f, 0.5f, 0.5f);
    // glRotatef(angle, 1.0f, 1.0f, 1.0f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);


    glColor3f(1.0f, 1.0f, 1.0f);
    // draw Cone
    for (int i = 0; i < nStack; ++i) {
        double z1 = height / nStack * i;
        double z2 = height / nStack * (i + 1);
        glBegin(GL_QUAD_STRIP);
            for (int j = 0; j <= nSlice; ++j) {
                double theta = (2 * PI) / nSlice * j;
                double sinTheta = sin(theta);
                double cosTheta = cos(theta);

                double x = cosTheta;
                double y = sinTheta;
                double nz = radius / height;
                double normLength = sqrt(x * x + y * y + nz * nz);

                double radius1 = (1 - ((double) i / nStack)) * radius;
                double radius2 = (1 - ((double) (i + 1) / nStack)) * radius;

                glNormal3d(x / normLength, y / normLength, nz / normLength);
                glTexCoord2d(1.0 / nSlice * j, 1.0 / nStack * (i + 1));
                glVertex3f(radius2 * x, radius2 * y, z2);

                glTexCoord2d(1.0 / nSlice * j, 1.0 / nSlice * i);
                glVertex3f(radius1 * x, radius1 * y, z1);
            }
        glEnd();
    }

    // draw bottom side
    glBegin(GL_TRIANGLE_FAN);
        glNormal3d(0, 0, -1);
        //glTexCoord2d(1.0 / nSlice * j, 1.0 / nStack * (i + 1));
        glVertex3f(0, 0, 0);
        for (int i = 0; i <= nSlice; ++i) {
            double theta = (2 * PI) / nSlice * i;
            double sinTheta = sin(theta);
            double cosTheta = cos(theta);

            double x = cosTheta;
            double y = sinTheta;

            glNormal3d(0, 0, -1);
            //glTexCoord2d(0.5 * (1 + x * radius), 0.5 * (1 + y * radius));
            glVertex3f(radius * x, radius * y, 0);
        }
    glEnd();
}