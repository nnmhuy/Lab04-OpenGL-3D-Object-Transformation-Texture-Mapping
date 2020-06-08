//
//  Hyperboloid.cpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/24/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "Hyperboloid.hpp"
#include "Texture.hpp"

Hyperboloid::Hyperboloid(int textureIndex) : Object(textureIndex) {
    
}

Hyperboloid::Hyperboloid(double a, double b, double c, double height, int nSlice, int nStack) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->height = height;
    this->nSlice = nSlice;
    this->nStack = nStack;
}

void Hyperboloid::draw() {

}


void Hyperboloid::drawScreen() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(1.0f, -1.0f, -7.0f); // Move right and into the screen
    glScalef(0.5f, 0.5f, 0.5f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    // glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    // glRotatef(20.0f, 1.0f, 0.0f, 0.0f);

    glBindTexture(GL_TEXTURE_2D, Texture::textureList[textureIndex]);
    // draw Hyperboloid
    for (int i = 0; i < nStack; ++i) {
        double z1 = (height / nStack * i) + (-height / 2.0);
        double z2 = (height / nStack * (i + 1)) + (-height / 2.0);

        double C1 = 1.0 + (z1 * z1) / (c * c);
        double C2 = 1.0 + (z2 * z2) / (c * c);
        glBegin(GL_QUAD_STRIP);
            for (int j = 0; j <= nSlice; ++j) {
                double theta = (2 * PI) / nSlice * j;
                double sinTheta = sin(theta);
                double cosTheta = cos(theta);

                double x = a * cosTheta;
                double y = b * sinTheta;
                
                glNormal3d(x, y, 0);
                glTexCoord2d(1.0 / nSlice * j, 1.0 / nStack * (i + 1));
                glVertex3f(C2 * x, C2 * y, z2);

                glTexCoord2d(1.0 / nSlice * j, 1.0 / nStack * i);
                glVertex3f(C1 * x, C1 * y, z1);
            }
        glEnd();
    }

    // draw top side
    glBegin(GL_TRIANGLE_FAN);
        glNormal3d(0, 0, 1);
        glTexCoord2d(0.5, 0.5);
        glVertex3f(0, 0, height / 2);
        for (int i = 0; i <= nSlice; ++i) {
            double C = 1.0 + (height / 2) * (height / 2) / (c * c);

            double theta = (2 * PI) / nSlice * i;
            double sinTheta = sin(theta);
            double cosTheta = cos(theta);

            double x = a * cosTheta;
            double y = b * sinTheta;

            glVertex3f(C * x, C * y, height / 2);
            glTexCoord2d(0.5 * (1 + cosTheta), 0.5 * (1 + sinTheta));
        }
    glEnd();

    // draw bottom side
    glBegin(GL_TRIANGLE_FAN);
    glNormal3d(0, 0, -1);
    glTexCoord2d(0.5, 0.5);
    glVertex3f(0, 0, -height / 2);
    for (int i = 0; i <= nSlice; ++i)
    {
        double C = 1.0 + (-height / 2) * (-height / 2) / (c * c);

        double theta = (2 * PI) / nSlice * i;
        double sinTheta = sin(theta);
        double cosTheta = cos(theta);

        double x = a * cosTheta;
        double y = b * sinTheta;

        glVertex3f(C * x, C * y, -height / 2);
        glTexCoord2d(0.5 * (1 + cosTheta), 0.5 * (1 + sinTheta));
    }
    glEnd();
}