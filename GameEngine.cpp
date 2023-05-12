#include "GameEngine.h"

GameEngine::GameEngine(){ _livesa = 3,_livesb =3;}    

const int Heart[5][5]= {
{0,1,0,1,0}, // our heart symbol for lives
{1,1,1,1,1},
{1,1,1,1,1},
{0,1,1,1,0},
{0,0,1,0,1},
};

void GameEngine::init(int player_position, int player_height, int player_width, int spell_size, int speed){
   // we must initialise certain functions and the interactive parts such as spells and players
    _spell.init(spell_size,speed);
 
    _player.init(player_position, player_height, player_width);

   
  _spellcasta=false;
  _spellfinisheda = true;
  
   _blockeda =true;

  _spell2.init(spell_size,speed);

    _player2.init(player_position, player_height, player_width);
   

  _spellcastb=false;
  _spellfinishedb = true;
    _blockedb =true;

  
}

void GameEngine::update(UserInput input, UserInput input2) {   
    // every cycle in the code we must update the players and spells with the new user inputs.
    // we must keep checking for goals or blocks so we can initialise the spells
 
    check_goala();
  
    valuea =_spell.update(input);// returns the value of spell for player a

   
    _player.update(input);


    check_spell_blocka(input);
    
     check_goalb();
  
    valueb= _spell2.update(input2);
   

    _player2.update(input2);
   

    check_spell_blockb(input2);
    
 


} 


void GameEngine::draw(N5110 &lcd) {
  // when rendering we must update the new graphics
    _spell.draw(lcd);
    _player.draw(lcd);
    _player2.draw(lcd);
     _spell2.draw(lcd);

if(_livesb>=1){lcd.drawSprite(0,0,5,5,(int*)Heart);}// we take a heart off based on the lives teh player is on
if(_livesb>=2){lcd.drawSprite(5,0,5,5,(int*)Heart);}
if(_livesb>=3){lcd.drawSprite(10,0,5,5,(int*)Heart);}
if(_livesa>=1){lcd.drawSprite(75,0,5,5,(int*)Heart);}
if(_livesa>=2){lcd.drawSprite(70,0,5,5,(int*)Heart);}
if(_livesa>=3){lcd.drawSprite(65,0,5,5,(int*)Heart);}

  
 
}

void GameEngine::check_spell_blocka(UserInput input){
Position2D spell_pos = _spell2.get_pos();
int size = _spell2.get_size();
int speed = abs(_spell2.get_velocity().x); 
if (spell_pos.x + size >= 0){

if(valueb == 1 ){// we check to see if the spell and the players joystick have the same directions

 if(input.d == N){
   _spell2.init(size,speed);


 }
}
  if(valueb == 3){
 if(input.d == E ){
     _spell2.init(size,speed);
  
 }
}
 if(valueb == 4 ){
 if(input.d == W ){

      _spell2.init(size,speed);
  

 }

}
 if(valueb == 2 ){
 if(input.d == S){
     _spell2.init(size,speed);

 }
}

 }
}

void GameEngine::check_goala() {
    
    Position2D spell_pos = _spell.get_pos();// if the spell goes off the board, we retrieve the position, initialise and remove a life. 
    int size = _spell.get_size();
    int speed = abs(_spell.get_velocity().x); 
    // check if ball position has gone off the left
    if (spell_pos.x + size >= WIDTH-1) {
        // reset the ball
        _spell.init(size,speed);
        _livesa--; 
    }   
}

int GameEngine::get_livesa(){return _livesa;}



void GameEngine::check_spell_blockb(UserInput input2){
Position2D spell_pos = _spell.get_pos(); // we get the position of player 1's spell
int size = _spell.get_size();
int speed = abs(_spell.get_velocity().x); 

 printf("Spell is:%d\n",valueb);

if (spell_pos.x + size <= WIDTH ){ // player 2 can block anywhere up to the spell hitting and losing a life
 printf("Spell Cast\n");
    if(valuea == 1 ){
    printf("Spell=1\n");
 if(input2.d == N){
   _spell.init(size,speed);
 }
}
  else if(valuea == 3){
          printf("Spell=3\n");
 if(input2.d == E ){
     _spell.init(size,speed);
 }
}
 else if(valuea== 4 ){
         printf("Spell=4\n");
 if(input2.d == W ){
      _spell.init(size,speed);
 }
}
 else if(valuea == 2 ){
         printf("Spell=2\n");
 if(input2.d == S){
     _spell.init(size,speed); 
 }
 }
 else if(valuea == 0){
     printf("0\n");
 }

 }
}


void GameEngine::check_goalb() {
    
    Position2D spell_pos = _spell2.get_pos();
    int size = _spell2.get_size();
    int speed = abs(_spell2.get_velocity().x);  // speed is magnitude of velocity
    // check if ball position has gone off the left
    if (spell_pos.x + size <= WIDTH-84) {
        // reset the ball
        _spell2.init(size,speed);
        _livesb--; 
    }   
}
int GameEngine::get_livesb(){return _livesb;} // can be called in the main function