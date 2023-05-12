/*   Pong Game
*    =========
*
*    Function:               Example pong game
*    Circuit Schematic No.:  9 and 14 : https://github.com/ELECXJEL2645/Circuit_Schematics
*    Required Libraries:     
*
*    Authored by:            Dr Craig Evans
*    Date:                   2021
*    Collaborators:          Andrew Knowles
*                            Dr Tim Amsdon 
*    Version:                1.0
*    Revision Date:          03/2023 
*    MBED Studio Version:    1.4.1
*    MBED OS Version:        6.12.0
*    Board:	                NUCLEO L476RG   */

///////////// includes /////////////////////
#include "mbed.h"
#include "Joystick.h"
#include "Joystick2.h"
#include "N5110.h"  
#include "GameEngine.h"
#include "Utils.h"

//////////HomePage Graphic////////////////



///////////// defines /////////////////////
#define PLAYER_WIDTH 2
#define PLAYER_HEIGHT 8
#define SPELL_SIZE 2
#define SPELL_SPEED 5
#define PLAYER2_WIDTH 2
#define PLAYER2_HEIGHT 8
#define SPELL2_SIZE 2
#define SPELL2_SPEED 5
///////////// objects ///////////////////
N5110 lcd(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
Joystick joystick(PC_1, PC_0);
Joystick2 joystick2(PC_3, PC_2);
DigitalIn buttonA(BUTTON1); //onboard user button
GameEngine game;


///////////// prototypes ///////////////
void init();
void render();
void welcome();
void info_page();
void game_over();
////////////////////////////////////////


int main() {
    init();      // initialise devices and objects
    welcome(); 
    info_page();  // waiting for the user to start 
    render();    // first draw the initial frame 
    int fps = 10;
    thread_sleep_for(1000/fps);  // and wait for one frame period - millseconds
    int livesa = 3;
    int livesb = 3;  // display lives on LEDs
    
    while (livesa > 0, livesb > 0) {  // keep looping while lives remain
        // read the joystick input and store in a struct
        UserInput input = {joystick.get_direction(),joystick.get_mag()};// 
        UserInput input2 = {joystick2.get_direction(),joystick2.get_mag()};
     game.update(input, input2);  // we need to enter 2 inputs one for player one and 1 for player 2
      
      livesa = game.get_livesa();
      livesb = game.get_livesb();
         // update the game engine based on input    
        render();                     // draw frame on screen
        thread_sleep_for(1000/fps); 

    }   
    game_over();
}

void init() {
    lcd.init(LPH7366_1);
    lcd.setContrast(0.5);
    joystick.init();
     joystick2.init();
    game.init(0,8,2,2,2);    
     
}

void render() {  // clear screen, re-draw and refresh
    lcd.clear();  
    game.draw(lcd);

    lcd.refresh();
}

void welcome() { // splash screen
lcd.printString("Harry Potter ",0,1);  
     lcd.printString("Dueling Club!",0,2);  
    lcd.printString("Press Nucleo",0,3);
    lcd.printString("Blue button",0,4);
    lcd.refresh();



 ThisThread::sleep_for(4000ms);
      
}

void info_page(){
     lcd.clear();
   lcd.printString("Move Joystick",0,1);  
     lcd.printString("Cast Spells",0,2);  
    lcd.printString("Block!",0,3);
    lcd.printString("3 Lives each",0,4);
    lcd.printString("Blue button",0,5);
    lcd.refresh();

      while (buttonA.read() == 1){

         ThisThread::sleep_for(100ms);
      
        }

}

void game_over() { // splash screen 
    while (1) {
       int a = game.get_livesa();
       int b = game.get_livesb();
        
        if(a == 0){
        lcd.clear();
        lcd.printString("  Player 1 Wins",0,2);  
        }
        else if(b == 0){
        lcd.clear();
        lcd.printString("  Player 2 Wins",0,2);  
        }
        lcd.refresh();
        ThisThread::sleep_for(250ms);
        lcd.clear();
        lcd.refresh();
        ThisThread::sleep_for(250ms);
    }
}