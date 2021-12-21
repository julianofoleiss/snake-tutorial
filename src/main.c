#include <stdlib.h>
#include <stdio.h>
#include "wasm4.h"
#include "snake.h"
#include "point.h"
#include "programState.h"
#include "gameState.h"

typedef enum STATE{
    ST_GAME,
    ST_TITLE,
    ST_GAME_OVER
} STATE;

PROGRAM_STATE states[3];
STATE currentState;

void start() {
    PALETTE[0] = 0xFBF7F3;
    PALETTE[1] = 0xE5B083;
    PALETTE[2] = 0x426E5D;
    PALETTE[3] = 0x20283D;

    currentState = ST_GAME;

    GAME_create(&states[ST_GAME]);

    states[currentState].start(&states[currentState]);
}

void update () {

    states[currentState].update(&states[currentState]);

    states[currentState].draw(&states[currentState]);

}
