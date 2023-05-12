#include "Spell2.h"

Spell2::Spell2() {}
const int SpellLeft[8][10] = {
{ 0,0,0,1,1,0,0,0,0,0,},
{ 0,0,1,1,1,0,0,0,0,0,},
{ 0,1,1,1,1,0,0,0,0,0,},
{ 1,1,1,1,1,1,1,1,1,1,},
{ 1,1,1,1,1,1,1,1,1,1,},
{ 0,1,1,1,1,0,0,0,0,0,},
{ 0,0,1,1,1,0,0,0,0,0,},
{ 0,0,0,1,1,0,0,0,0,0,},

};

const int SpellRight[8][10] = {
{ 0,0,0,0,0,1,1,0,0,0,},
{ 0,0,0,0,0,1,1,1,0,0,},
{ 0,0,0,0,0,1,1,1,1,0,},
{ 1,1,1,1,1,1,1,1,1,1,},
{ 1,1,1,1,1,1,1,1,1,1,},
{ 0,0,0,0,0,1,1,1,1,0,},
{ 0,0,0,0,0,1,1,1,0,0,},
{ 0,0,0,0,0,1,1,0,0,0,},

};


const int SpellUp[8][10] = {
{ 0,0,0,1,1,1,1,0,0,0,},
{ 0,0,1,1,1,1,1,1,0,0,},
{ 1,1,1,1,1,1,1,1,1,1,},
{ 1,1,1,1,1,1,1,1,1,1,},
{ 0,0,0,0,1,1,0,0,0,0,},
{ 0,0,0,0,1,1,0,0,0,0,},
{ 0,0,0,0,1,1,0,0,0,0,},
{ 0,0,0,0,1,1,0,0,0,0,},
};
const int SpellDown[8][10] = {
{ 0,0,0,0,1,1,0,0,0,0,},
{ 0,0,0,0,1,1,0,0,0,0,},
{ 0,0,0,0,1,1,0,0,0,0,},
{ 0,0,0,0,1,1,0,0,0,0,},
{ 1,1,1,1,1,1,1,1,1,1,},
{ 0,1,1,1,1,1,1,1,1,0,},
{ 0,0,1,1,1,1,1,1,0,0,},
{ 0,0,0,1,1,1,1,0,0,0,},
};

void Spell2::init(int size, int speed) {
  
    _size = size;
    _x = 80;// iniatlise the position of the spell and other bool values so we can cast a spell

    _velocity.x = 5;

    _spellb = 0;
    _spellcastb = false;
    _spellfinishedb = true;

}

void Spell2::draw(N5110 &lcd) {
 
  if(_spellb==4){
    lcd.drawSprite(_x,20,8,10,(int*)SpellLeft); // we call 
 }

 else if(_spellb==3){
 lcd.drawSprite(_x,20,8,10,(int*)SpellRight); 
 }
else if(_spellb==1){
   lcd.drawSprite(_x,20,8,10,(int*)SpellUp); 
    }
else if(_spellb==2){
    lcd.drawSprite(_x,20,8,10,(int*)SpellDown); 
    }
}

int Spell2::update(UserInput input){
 
    if(_spellfinishedb == true){ // can only enter this function to call a new spell once the spell is either blocked or hits its target
    
    if (input.d == N) {// check the direction of the players joystick to call appropriate spell
   No();
     }
 else if (input.d == S) {
 So();
    }
  else if (input.d == E) {
Ea();
    }
 else if (input.d == W) {
  We();
    }
    else{
        _spellb = 0;
    }

}
if(_spellcastb == true){
_x += -_velocity.x;
}
  return _spellb; // returns this to the main to be used in the checks for a block
  }



void Spell2::set_velocity(Position2D v){
   
    _velocity.x = v.x;
}

void Spell2::set_pos(Position2D p) {

    _x = p.x;
}

Position2D Spell2::get_velocity(){ return {_velocity.x}; }

Position2D Spell2::get_pos() { return {_x}; }

int Spell2::get_size() { return _size; }
int Spell2::get_spell() {return _spellb;}


void Spell2::No(){
_spellb = 1;_spellcastb = true; _spellfinishedb = false;
}
void Spell2::So(){
_spellb = 2;_spellcastb = true; _spellfinishedb = false;
}
void Spell2::We(){
_spellb = 4;_spellcastb = true; _spellfinishedb = false;
}
void Spell2::Ea(){
_spellb = 3;_spellcastb = true; _spellfinishedb = false;
}



