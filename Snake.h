//
//  Snake.hpp
//  glutapp
//
//  Created by Josh Gialis on 4/30/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#ifndef Snake_hpp
#define Snake_hpp

class Snake {
    
private:
    int X;
    int Y;
    int gridX;
    int gridY;
    
public:
    Snake(){};
    Snake(int X, int Y, int gridX, int gridY) : X(X), Y(Y), gridX(gridX), gridY(gridY) {}
    void drawSnake(int,int);
    
};

#endif /* Snake_hpp */
