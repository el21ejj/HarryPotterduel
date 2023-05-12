#ifndef PLAYER_H
#define PLAYER_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"

class Player
{
public:

    Player();
    void init(int x,int height,int width);
    void draw(N5110 &lcd);
    void update(UserInput input);

   int get_stance();
 int _stance;
 int _blockeda;
 
private:
int _height;
int _width;
    int _x;
 
    int _speed;
 



};
#endif