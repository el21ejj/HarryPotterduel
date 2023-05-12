#ifndef PLAYER2_H
#define PLAYER2_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"

class Player2
{
public:

    Player2();
    void init(int x,int height,int width);
    void draw(N5110 &lcd);
    void update(UserInput input2);
    void add_score();
    int get_score();
    Position2D get_pos();
   int get_stance();
   int get_spell();
 int _stance;

int _blockedb;
private:

    int _height;
    int _width;
    int _x;
    int _y;
    int _speed;
    int _score;


};
#endif