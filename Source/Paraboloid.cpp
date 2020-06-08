//
//  Paraboloid.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Paraboloid.hpp"

Paraboloid::Paraboloid(double a, double b, double height, int nSlice, int nStack) {
    this->a = a;
    this->b = b;
    this->height = height;
    this->nSlice = nSlice;
    this->nStack = nStack;
}

void Paraboloid::draw() {

}


void Paraboloid::drawScreen() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(3.0f, -1.0f, -7.0f); // Move right and into the screen
    glScalef(0.5f, 0.5f, 0.5f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    // glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    // glRotatef(20.0f, 1.0f, 0.0f, 0.0f);


    glColor3f(1.0f, 1.0f, 1.0f);
    // draw Paraboloid
    for (int i = 0; i < nStack; ++i) {
        double z1 = (height / nStack * i);
        double z2 = (height / nStack * (i + 1));

        glBegin(GL_QUAD_STRIP);
            for (int j = 0; j <= nSlice; ++j) {
                double theta = (2 * PI) / nSlice * j;
                double sinTheta = sin(theta);
                double cosTheta = cos(theta);

                double x = a * cosTheta;
                double y = b * sinTheta;
                
                glNormal3d(x, y, 0);
                glTexCoord2d(1.0 / nSlice * j, 1.0 / nStack * (i + 1));
                glVertex3f(z2 * x, z2 * y, z2 * z2);

                glTexCoord2d(1.0 / nSlice * j, 1.0 / nStack * i);
                glVertex3f(z1 * x, z1 * y, z1 * z1);
            }
        glEnd();
    }

    // draw bottom side
    glBegin(GL_TRIANGLE_FAN);
    glNormal3d(0, 0, 1);
    //glTexCoord2d(1.0 / nSlice * j, 1.0 / nStack * (i + 1));
    glVertex3f(0, 0, height);
    for (int i = 0; i <= nSlice; ++i)
    {
        double theta = (2 * PI) / nSlice * i;
        double sinTheta = sin(theta);
        double cosTheta = cos(theta);

        double x = a * cosTheta;
        double y = b * sinTheta;

        glVertex3f(height * x, height * y, height);
        glTexCoord2d(0.5 * (1 + cosTheta), 0.5 * (1 + sinTheta));
    }
    glEnd();
}