#ifndef Config_hpp
#define Config_hpp

#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/GLUT.h>

class Config {
public:
    const static int MAX_COORDINATE = 500;
    static int color;
    static int main_menu_id;
};

#endif /* Config_hpp */
