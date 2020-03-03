#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <sstream>
#include "Snake.h"
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


void Snake::drawSnake(int  X, int  Y)
{
    if(X <= 0 || Y <= 0 || X == gridX - 1 || Y == gridY - 1)
    {

        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2i(X, Y);
        glVertex2i(X+ 1, Y);
        glVertex2i(X+ 1, Y - 1);
        glVertex2i(X, Y - 1);
        glVertex2i(X, Y);
        glEnd();

        //NOT THE RIGHT WAY TO DO THIS!
        X = -2;

    }

    else
    {
        glColor3f(1.0, 1.0, 1.0);
    }
    glBegin(GL_POLYGON);
    glVertex2i(X, Y);
    glVertex2i(X + 1,  Y);
    glVertex2i(X + 1, Y + 1);
    glVertex2i(X, Y + 1);
    glEnd();
    
}
