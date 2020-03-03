#ifndef Game_h
#define Game_h

#include <sstream>

#include "TextBox.h"
#include "Snake.h"

class Game {

private:
    int gridX;
    int gridY;
    int FPS;
    int X[200] = {20, 20, 20, 20, 20};
    int Y[200] = {20, 19, 18, 17, 16};
    int foodX;
    int foodY;
    int Points;
    int initSnakeLength;
    std::string sPoints;
    std::stringstream ss;
    
    
    bool escape;
  
    float red;
    float green;
    float blue;
    std::vector<TextBox*> TB;
    bool foodActive;

   
    
public:
    Game(){}
    Game(int, int, int, int);
    void drawGrid();
    void drawSnake();
    void drawFood();
    int getFPS();
    void RANDOM(int&, int&);
    void RANDOMCOLOR(float & x, float & y, float & z);
    void unitSquare(int, int);
    void setXPos(){ X[0] += 1;}
    void setXNeg() { X[0] -= 1;}
    void setYPos() { Y[0] += 1;}
    void setYNeg() { Y[0] -= 1;}
    void convertToString();
    
    void setEscape(bool);

};

#endif /* Game_h */
