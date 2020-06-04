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
#include <vector>

#include <GL/glut.h>
#include <SOIL/SOIL.h>

#include "Config.hpp"
#include "Object.hpp"
#include "Point.hpp"

using namespace std;

GLfloat anglePyramid = 0.0f; // Rotational angle for pyramid [NEW]
int refreshMills = 15; // refresh interval in milliseconds [NEW]
GLuint texture[1]; // Storage For One Texture ( NEW )

int loadGLTextures() // Load Bitmaps And Convert To Textures
{
    cout << "Load texture" << endl;
    /* load an image file directly as a new OpenGL texture */
    texture[0] = SOIL_load_OGL_texture
    (
    "./Data/earth2048.bmp",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
    );

    if(texture[0] == 0) {
        cout << "Load texture FAIL" << endl;
        return false;
    }
        
    cout << "Load texture SUCCESS" << endl;
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    return true;
}

void RenderScreen(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW); // To operate on model-view matrix
 
    // Render object from object list
    int nObject = Object::objects.size();
    for (int i = 0; i < nObject; ++i) {
        Object::objects[i]->drawScreen();
    }

    glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)
}

//  Set up the rendering state, set only once before rendering
void SetupRC(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f); // Set background depth to farthest
    glEnable(GL_DEPTH_TEST); // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL); // Set the type of depth-test
    glShadeModel(GL_SMOOTH); // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
}

// Called by GLUT library when the window has changed size
void ChangeSize(GLsizei width, GLsizei height)
{
    // Compute aspect ratio of the new window
    if (height == 0) height = 1; // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);
    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
    glLoadIdentity(); // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Called back when timer expired [NEW] */
void timer(int value) {
    // update angle of all shape
    int nObject = Object::objects.size();
    for (int i = 0; i < nObject; ++i) {
        Object::objects[i]->angle += 0.5f;
    }

    glutPostRedisplay(); // Post re-paint request to activate display()
    glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

void initObjectList() {
    // new cube
    Object::objects.push_back(Object::constructObject(0));
    Object::objects.push_back(Object::constructObject(1));
    Object::objects.push_back(Object::constructObject(2));

    int nObject = Object::objects.size();
    for (int i = 0; i < nObject; ++i) {
        Object::objects[i]->draw();
    }
}


int Config::WIDTH = 0;
int Config::HEIGHT = 0;
vector<Object*> Object::objects;

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(Config::ORIGINAL_WIDTH, Config::ORIGINAL_HEIGHT);
    glutCreateWindow("3D Object Transformation");
    
    initObjectList();
    loadGLTextures();
    SetupRC();

    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScreen);

    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
