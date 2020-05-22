//
//  Polygon.hpp
//  Lab02_Object_Coloring
//
//  Created by Huy Nguyen Ngoc Minh on 5/2/20.
//  Copyright © 2020 Huy Nguyen Ngoc Minh. All rights reserved.
//

#ifndef Polygon_hpp
#define Polygon_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

#include "Config.hpp"
#include "Object.hpp"
#include "Point.hpp"

class Polygon : public Object {
public:
    static Point top_left, bottom_right;
    static vector <Point> currentPoints;
    static Object * drawingPolygon;
    void getParameters(Point start_point, Point end_point) override;
    void draw() override;
    void drawScreen() override;
    static void handleInsertPoint(int button, int state, int x, int y);
};


#endif /* Polygon_hpp */
