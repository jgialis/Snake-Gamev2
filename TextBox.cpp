#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include "TextBox.h" 
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif



void TextBox::draw() {
    glColor3f( r, g, b );
    glRasterPos2f(x, y);
    
    for (int i = 0; i < length; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    
}
