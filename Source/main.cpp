//
//  main.cpp
//  Lab02_Object_Coloring
//
//  Created by Huy Nguyen Ngoc Minh on 5/2/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <fstream>

#include <GL/glut.h>

#include "Config.hpp"
#include "Point.hpp"

using namespace std;

void RenderScreen(void) {
    // temporary ignore for not deleting drawn shapes
    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT);

    cout << "Re-render window" << endl;

    glutSwapBuffers();
}

//  Set up the rendering state, set only once before rendering
void SetupRC(void) {
    // Set clear color to black
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
}

// Called by GLUT library when the window has changed size
void ChangeSize(GLsizei w, GLsizei h)
{
    cout << "Handle change size: " << w << " " << h << endl;
    // Set Viewport to window dimensions
    // glViewport(x, y, w, h) => (x,y): lower-left point of viewport; (w, h): width, height
    
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, w, h);

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(0, w, h, 0, 1, -1);
    // all future transformation will affect model

    Config::WIDTH = w;
    Config::HEIGHT = h;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int Config::WIDTH = 0;
int Config::HEIGHT = 0;

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(Config::ORIGINAL_WIDTH, Config::ORIGINAL_HEIGHT);
    glutCreateWindow("3D Object Transformation");

    SetupRC();

    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScreen);
    glutMainLoop();
    return 0;
}
