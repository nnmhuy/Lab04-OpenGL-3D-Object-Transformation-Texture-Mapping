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
#include "ColorMenu.hpp"
#include "DrawMenu.hpp"
#include "Polygon.hpp"

using namespace std;

int window;
int value;

void RenderScreen(void) {
    // temporary ignore for not deleting drawn shapes
    // Clear the window with current clearing color
    glClear(GL_DEPTH_BUFFER_BIT);
    // cout << "Re-render window" << endl;
    // Flush drawing commands
    glFlush();
}

//  Set up the rendering state, set only once before rendering
void SetupRC(void) {
    // Set clear color to black
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
}

void mainMenu(int num){
    cout << "MAIN MENU" << endl;
    if(num == 0){
        glutDestroyWindow(window);
        exit(0);
    } else {
        value = num;
    }
    //glutPostRedisplay();
}

void createMenu(void){
    int draw_submenu_id = glutCreateMenu(DrawMenu::handleToggleMenu);
    glutAddMenuEntry("Ellipse", 1);
    glutAddMenuEntry("Rectangle", 2);
    glutAddMenuEntry("Circle", 3);
    glutAddMenuEntry("Star", 4);
    glutAddMenuEntry("Polygon", 0);
    
    int color_submenu_id = glutCreateMenu(ColorMenu::handleToggleMenu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);
    
    Config::main_menu_id = glutCreateMenu(mainMenu);
    glutAddSubMenu("Draw", draw_submenu_id);
    glutAddSubMenu("Color", color_submenu_id);
    glutAddMenuEntry("Exit", 0);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
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


Point ColorMenu::p;
int ColorMenu::currentColor = 1;
int DrawMenu::shape = 0;
Point DrawMenu::start_point;
Point DrawMenu::end_point;
vector <Point> Polygon::currentPoints;
int Config::main_menu_id;
int Config::WIDTH = 0;
int Config::HEIGHT = 0;

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(Config::ORIGINAL_WIDTH, Config::ORIGINAL_HEIGHT);
    glutCreateWindow("Coloring Objects");

    SetupRC();
    createMenu();
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScreen);
    glutMainLoop();
    return 0;
}
