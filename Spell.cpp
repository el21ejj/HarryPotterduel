#include "Spell.h"

Spell::Spell() {}

//these are the sprites for the different spells
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

void Spell::init(int size, int speed) {
    // we must initialise the spells position and speed it travels at
    _size = size;
    _x = 0;

    _velocity.x = 5;
    
    _spellcasta = false;
    _spellfinisheda = true;
    _spella = 0;

}

void Spell::draw(N5110 &lcd) {
// we draw the spell depending on what spell is cast based on user input
  if(_spella==4){
    lcd.drawSprite(_x,20,8,10,(int*)SpellLeft); 
    
 }

 else if(_spella==3){
 lcd.drawSprite(_x,20,8,10,(int*)SpellRight); 
 }
else if(_spella==1){
   lcd.drawSprite(_x,20,8,10,(int*)SpellUp); 
    }
else if(_spella==2){
    lcd.drawSprite(_x,20,8,10,(int*)SpellDown); 
    }
}

int Spell::update(UserInput input){
 
    if(_spellfinisheda == true){
    
    if (input.d == N) {
_spella = 1; _spellcasta = true; _spellfinisheda = false;
printf("Spell is:%d\n",_spella);
     }
 else if (input.d == S) {
 _spella = 2;_spellcasta = true; _spellfinisheda = false;
printf("Spell is:%d\n",_spella);
    }
  else if (input.d == E) {
_spella = 3;_spellcasta = true; _spellfinisheda = false;

printf("Spell is:%d\n",_spella);
    }
 else if (input.d == W) {
  _spella = 4;_spellcasta = true; _spellfinisheda = false;
  printf("Spell is:%d\n",_spella);
    }
}
if(_spellcasta == true){
_x += _velocity.x;
 printf("Spell is:%d\n",_spella);
}
return _spella;
}
void Spell::set_velocity(Position2D v){
    _velocity.x = v.x;
}

void Spell::set_pos(Position2D p) {

    _x = p.x;
}

Position2D Spell::get_velocity(){ return {_velocity.x}; }

Position2D Spell::get_pos() { return {_x}; }

int Spell::get_size() { return _size; }

int Spell::get_spell() { printf("Spell is:%d\n",_spella);return _spella;}


void Spell::No(){
    printf("Spella = 1\n");
_spella = 1;_spellcasta = true; _spellfinisheda = false;
printf("Spell is:%d\n",_spella);
}
void Spell::So(){
    printf("Spella = 2\n");
_spella = 2;_spellcasta = true; _spellfinisheda = false;
printf("Spell is:%d\n",_spella);
}
void Spell::We(){
    printf("Spella = 4\n");
_spella = 4;_spellcasta = true; _spellfinisheda = false;
printf("Spell is:%d\n",_spella);
}
void Spell::Ea(){
    printf("Spella = 3\n");
_spella = 3;_spellcasta = true; _spellfinisheda = false;
printf("Spell is:%d\n",_spella);
}
