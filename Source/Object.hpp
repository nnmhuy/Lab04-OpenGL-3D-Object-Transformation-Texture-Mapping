//
//  Object.hpp
//  Lab01
//
//  Created by Huy Nguyen Ngoc Minh on 4/23/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <fstream>
#include <vector>

#include <GL/glut.h>

#include "Point.hpp"

using namespace std;

class Object {
public:
    Point center;
    vector <Point> base_points;
    static vector<Object*> objects;
    static Object* constructObject(int type);
    static int getClickedObjectIndex(Point p);
    virtual void getParameters(Point start_point, Point end_point) = 0;
    virtual void draw() = 0;
    virtual void drawScreen() = 0;
    bool isPointInside(Point point);
    void translate(int dx, int dy); // translate in x and translate in y
    void scale(double sx, double sy); // scale in x and scale in y
    void rotate(int alpha); // in degree
};

#endif /* Object_hpp */
