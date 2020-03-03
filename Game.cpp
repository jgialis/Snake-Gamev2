#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <sstream>
#include "Game.h"
#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


Game::Game(int gridX, int gridY, int FPS, int Points) : gridX(gridX), gridY(gridY), FPS(FPS), Points(Points)
{
    sPoints = "0";
    red = 0;
    green = 0;
    blue = 0;
    initSnakeLength = 5;
    foodActive = true;
    
    
    TB.push_back(new TextBox("GAME OVER!", 14.9, 20, 10, 1, 1, 1));
    TB.push_back(new TextBox("SCORE: ", 16, 17, 10, 1, 1, 1));
    TB.push_back(new TextBox("Created by Josh Gialis ", 2 , 3, 22, 1, 1, 1));
    
    
    escape = false;
    
}


void Game::setEscape(bool escape)
{
    this->escape = escape;
}
void Game::drawGrid()
{
    TB[2]->draw();
    for (int i = 6; i < gridX - 5; i ++)
    {
        for (int j = 6; j < gridY - 5; j++)
            unitSquare(i, j);
    }
}



void Game::RANDOM(int & x, int & y)
{
    int max = gridX - 7;
    int min = 7;
    srand(time(NULL));
    x = min + rand() % (max - min);
    y = min + rand() % (max - min);
}



void Game::RANDOMCOLOR(float & x, float & y, float & z)
{
    srand(time(NULL));
    x = (rand() % 10) * 0.1;
    y = (rand() % 10) * 0.1;
    z = (rand() % 10) * 0.1;
}


void Game::unitSquare(int x, int y)
{
    if (x == 6 || x == (gridX - 6) || y == 6 || y == (gridY - 6))
    {
        glColor3f(red, green, blue);
        glBegin(GL_POLYGON);
        glVertex2i(x, y);
        glVertex2i(x + 1,  y);
        glVertex2i(x + 1, y + 1);
        glVertex2i(x, y + 1);
        glEnd();
    }
    
    else
    {
        glLineWidth(1.0);
        glColor3f(0.0, 0.0, 0.0);
    }
    
    glBegin(GL_LINE_LOOP);
    glVertex2i(x, y);
    glVertex2i(x + 1,  y);
    glVertex2i(x + 1, y + 1);
    glVertex2i(x, y + 1);
    glEnd();
    
}

void Game::drawFood()
{
    
    if (foodActive)
    {
        RANDOM(foodX, foodY);
        RANDOMCOLOR(red, green, blue);
        
        while (X[0] == foodX && Y[0] == foodY)
            RANDOM(foodX, foodY);
    }
    
    foodActive = false;
    
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    glVertex2i(foodX, foodY);
    glVertex2i((foodX) + 1,  (foodY));
    glVertex2i((foodX) + 1, (foodY) + 1);
    glVertex2i((foodX), (foodY) + 1);
    glEnd();
    
    if (X[0] == foodX && Y[0] == foodY)
    {
        foodActive = true;
        Points++;
        initSnakeLength += 10;
    }
}



void Game::drawSnake()
{
    convertToString();
    TB.push_back(new TextBox(sPoints, 16, 15, 10, 1, 1, 1));
    TB[2]->draw();
    glColor3f(1.0, 0.0, 0);
    glRectd(X[0], Y[0], X[0] + 1, Y[0] + 1);
    for (int i = initSnakeLength - 1; i > 0; i--)
    {
        X[i] = X[i - 1];
        Y[i] = Y[i - 1];
    }
   
    for (int i = 2; i < initSnakeLength; i++)
    {
        glColor3f(1.0, 1.0, 1.0);
        
        glRectd(X[i], Y[i], X[i] + 1, Y[i] + 1);
    }
    
    //BOUNDARY OF THE BOARD VALIDATION
    if(X[0] <= 6 || Y[0] <= 6 || X[0] == gridX - 6 || Y[0] == gridY - 6)
    {
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2i(X[0], Y[0]);
        glVertex2i(X[0] + 1, Y[0]);
        glVertex2i(X[0] + 1, Y[0] - 1);
        glVertex2i(X[0], Y[0] - 1);
        glEnd();
        
        //NOT THE RIGHT WAY TO DO THIS!
        X[0] = -2;
        foodX = -2;
        foodY = -2;
        convertToString();
        TB.push_back(new TextBox(sPoints, 16, 15, 10, 1, 1, 1));
        for (int i = 0; i < TB.size(); i++)
            TB[i]->draw();
    
    }
    
    
    for (int i = 5 ; i < initSnakeLength; i++)
    {
        if(X[0] == X[i] && Y[0] == Y[i] )
        {
            convertToString();
            TB.push_back(new TextBox(sPoints, 16, 15, 10, 1, 1, 1));
            for (int i = 0; i < TB.size(); i++)
                TB[i]->draw();
            exit(0);
        }
    }
}


int Game::getFPS()
{
    return FPS;
}



void Game::convertToString()
{
    ss << Points << std::endl;
    sPoints = ss.str();
}







