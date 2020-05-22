//
//  AffineTransformMenu.cpp
//  Lab02_Object_Coloring
//
//  Created by Huy Nguyen Ngoc Minh on 5/2/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#include "AffineTransformMenu.hpp"
#include "Object.hpp"

void AffineTransformMenu::getMouseClickPosition(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glutMouseFunc(NULL);
        cout << "Choose object at point: " << x << " " << y << endl;
        p = Point(x, y);
        currentObjectIndex = Object::getClickedObjectIndex(p);
        cout << "Selected: " << currentObjectIndex << endl;

        glutKeyboardFunc(mapKeyboardToFunctions);
        glutSpecialFunc(mapSpecialKeyboardToFunctions);
    } else {
        if (button != GLUT_LEFT_BUTTON) {
            glutMouseFunc(NULL);
            cout << "Cancelled color" << endl;
        }
    }
}

void AffineTransformMenu::handleToggleMenu(int select){
    cout << "AFFINE TRANSFORM MENU" << endl;
    if (select == 1) { // select object
        glutMouseFunc(getMouseClickPosition);   
    } else { // unselect object
        AffineTransformMenu::currentObjectIndex = -1;
    }
}

void AffineTransformMenu::mapSpecialKeyboardToFunctions(int key, int x, int y) {
    // up, down, left, right: translate
    if (currentObjectIndex == -1) return;
    cout << "Pressed: " << key << endl;
    switch (key) {
        case 100: // <--
            Object::objects[currentObjectIndex]->translate(-1, 0);
            break;
        case 101: // ^
            Object::objects[currentObjectIndex]->translate(0, -1);
            break;
        case 102: // -->
            Object::objects[currentObjectIndex]->translate(1, 0);
            break;
        case 103: // \/
            Object::objects[currentObjectIndex]->translate(0, 1);
            break;
        case 27: // esc
            // not selecting any object
            currentObjectIndex = -1;
            // detach keyboard func
            glutSpecialFunc(NULL);
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void AffineTransformMenu::mapKeyboardToFunctions(unsigned char key, int x, int y) {
    // l: rotate left; r: rotate right
    // +, -: scale
    if (currentObjectIndex == -1) return;
    cout << "Pressed: " << key << endl;
    switch (key) {
        case 'l': // l
            Object::objects[currentObjectIndex]->rotate(-1);
            break;
        case 'r': // r
            Object::objects[currentObjectIndex]->rotate(1);
            break;  
        case '+': // +
            Object::objects[currentObjectIndex]->scale(1.1, 1.1);
            break;
        case '-': // -
            Object::objects[currentObjectIndex]->scale(0.91, 0.91);
            break;
        case 27: // esc
            // not selecting any object
            currentObjectIndex = -1;
            // detach keyboard func
            glutSpecialFunc(NULL);
            break;
        default:
            break;
    }
    glutPostRedisplay();
}
