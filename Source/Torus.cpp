//
//  Torus.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Torus.hpp"

Torus::Torus(double innerRadius, double outterRadius, int nSlice, int nRing) {
    this->innerRadius = innerRadius;
    this->outterRadius = outterRadius;
    this->nSlice = nSlice;
    this->nRing = nRing;
}

void Torus::draw() {

}


void Torus::drawScreen() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(-1.0f, -1.0f, -7.0f); // Move right and into the screen
    glScalef(0.5f, 0.5f, 0.5f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    // glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    // glRotatef(20.0f, 1.0f, 0.0f, 0.0f);


    double centerRadius = (innerRadius + outterRadius) / 2.0;
    double tubeRadius = outterRadius - centerRadius;

    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < nSlice; ++i) {
        double s1 = (double)i / nSlice;
        double s2 = (double)(i + 1) / nSlice;
        double theta1 = (2 * PI) * s1;
        double theta2 = (2 * PI) * s2;
        double centerSin1 = sin(theta1);
        double centerCos1 = cos(theta1);
        double centerSin2 = sin(theta2);
        double centerCos2 = cos(theta2);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= nRing; ++j)
        {
            double t = (double)j / nRing;
            double alpha = (2 * PI) * t;
            double cosAlpha = cos(alpha);
            double sinAlpha = sin(alpha);

            double x1 = centerCos1 * (centerRadius + tubeRadius * cosAlpha);
            double y1 = centerSin1 * (centerRadius + tubeRadius * cosAlpha);
            double z1 = sinAlpha * tubeRadius;

            glNormal3d(centerCos1 * cosAlpha, centerSin1 * cosAlpha, sinAlpha);
             glTexCoord2d(s1, t);
            glVertex3d(x1, y1, z1);

            double x2 = centerCos2 * (centerRadius + tubeRadius * cosAlpha);
            double y2 = centerSin2 * (centerRadius + tubeRadius * cosAlpha);
            double z2 = sinAlpha * tubeRadius;

            glNormal3d(centerCos2 * cosAlpha, centerSin2 * cosAlpha, sinAlpha);
             glTexCoord2d(s2, t);
            glVertex3d(x2, y2, z2);
        }
        glEnd();
    }
}