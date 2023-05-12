#ifndef SPELL2_H
#define SPELL2_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"  // for Position


/** Ball Class
@author Dr Craig A. Evans, University of Leeds
@brief Controls the ball in the Pong game 
@date Febraury 2017
*/ 

class Spell2
{

public:
    Spell2();
    void init(int size,int speed);
    void draw(N5110 &lcd);
    int update(UserInput input);
    /// accessors and mutators
    void set_velocity(Position2D v);
    Position2D get_velocity();
    Position2D get_pos();
    int get_size();
    int get_spell();
    void set_pos(Position2D p);
    bool _spellcastb;

    bool _spellfinishedb;
private:

    Position2D _velocity;
    int _size;
    int _x;
    int _y;
    int _speed;
     int _spellb;
   void Ea();
   void No();
   void We();
   void So();
 

};
#endif