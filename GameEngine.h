#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "mbed.h"
#include "N5110.h"
#include "Spell.h"
#include "Spell2.h"
#include "Utils.h"
#include "Player.h"
#include "Player2.h"



class GameEngine {
    public:
        GameEngine();  // pass in the lcd object from the main file
        void init(int player_position,int player_height,int player_width,int spell_size,int speed);
        void update(UserInput input, UserInput input2);
        void draw(N5110 &lcd);
        int get_livesa();
          int get_livesb();
      
        bool _spellcasta;
        bool _spellfinisheda;
    
        bool  _blockeda;
         int valuea;
         int valueb;
          bool _spellcastb;
        bool _spellfinishedb;

        bool  _blockedb;
    
    
        int _livesa;
         int _livesb;
    private:

        void check_goala();
     
        void check_spell_blocka(UserInput input);
        
        void check_goalb();
     
        void check_spell_blockb(UserInput input2);
   
        Spell _spell;
        Spell2 _spell2;

        Player _player;
        Player2 _player2;

    
};

#endif