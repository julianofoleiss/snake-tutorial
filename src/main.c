#include <stdlib.h>
#include <stdio.h>
#include "wasm4.h"
#include "snake.h"
#include "point.h"
#include "programState.h"
#include "gameState.h"
#include "globals.h"
#include "gameOverState.h"

//TODO: change "start" state callback function to "enter".

extern STATE currentState;
extern PROGRAM_STATE states[];

void start() {
    PALETTE[0] = 0xFBF7F3;
    PALETTE[1] = 0xE5B083;
    PALETTE[2] = 0x426E5D;
    PALETTE[3] = 0x20283D;

    currentState = ST_GAME;

    GAME_create(&states[ST_GAME]);
    GAMEOVER_create(&states[ST_GAME_OVER]);

    states[currentState].start(&states[currentState]);
}

void update () {
    STATE oldState = currentState;

    states[currentState].update(&states[currentState]);
    states[oldState].draw(&states[oldState]);

    if(oldState != currentState){
        //trace("aaa");
        states[currentState].start(&states[currentState]);
    }
}
