#include <iostream>
#include <cmath>
#include <vector>
#include "Game.h"
#include "TextBox.h"
#include <ctime>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#define COLUMNS 50
#define ROWS 50
#define MILLI 1000

//Some global variavles
bool up, down, right, left = false;
int x, y = 0;

//Default 'UP' direction
std::string direction = "UP";


//GLUT Function Protoypes
void appDrawScene();
void init();
void windowResize(int,int);
void Timer(int);
void appSpecialUp(int, int, int);
void movement();
void idle();
void appKeyBoard(unsigned char, int, int);


//Instance of Game class
 Game * pG = new Game(COLUMNS, ROWS, 15, 0);


//Main Function
int main(int argc, char** argv)
{
    
    

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    // Setup window position, size, and title
    glutInitWindowPosition(20, 60);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Snake Game ");
   glutDisplayFunc(appDrawScene);
    glutReshapeFunc(windowResize);
    glutTimerFunc(0, Timer, 0);
    glutSpecialFunc(appSpecialUp);
    
    glutKeyboardFunc(appKeyBoard);
    glEnable(GL_POINT_SMOOTH);
    init();
    glutMainLoop();
}

void appDrawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    pG->drawGrid();
    pG->drawSnake();
    pG->drawFood();
   movement();
    
    
    glutSwapBuffers();
}

void init()
{
   glClearColor(0.0, 0.0, 0.0, 0.4);
}

void windowResize(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void Timer(int time)
{
    glutPostRedisplay();
    glutTimerFunc(MILLI/pG->getFPS(), Timer, 0);
}


void appSpecialUp(int key, int x, int y)
{
    switch (key)
    {
            //LEFT
        case 100:
            if (direction != "RIGHT")
                direction = "LEFT";
            break;

            //UP
        case 101:
            if (direction != "DOWN")
                direction = "UP";
            break;
            
            //RIGHT
        case 102:
            if (direction != "LEFT")
                direction = "RIGHT";
            break;
            
            //DOWN
        case 103:
            if (direction != "UP")
                direction = "DOWN";
            break;
            
        default:
            break;
    }
}



void movement()
{
        if (direction == "UP") pG->setYPos();
        else if (direction == "DOWN") pG->setYNeg();
        else if (direction == "LEFT") pG->setXNeg();
        else if (direction == "RIGHT") pG->setXPos();
}


void appKeyBoard(unsigned char key, int x, int y)
{
    switch (key) {
        case ' ':
            pG->setEscape(true);
            break;
            
        default:
            break;
    }
}
