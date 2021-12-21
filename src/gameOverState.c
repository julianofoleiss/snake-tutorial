#include "programState.h"
#include "gameState.h"
#include "wasm4.h"
#include "globals.h"
#include "utils.h"
#include <stdio.h>

extern STATE currentState;
extern PROGRAM_STATE states[];
static uint8_t showBeatHighScore;

void GAMEOVER_update(PROGRAM_STATE *ps){
    ps;
    if(*GAMEPAD1 & (BUTTON_1 | BUTTON_2))
        currentState = ST_GAME;
}

void GAMEOVER_draw(PROGRAM_STATE *ps){
    ps;
    uint32_t finalScore = GAME_getScore(&states[ST_GAME]);
    uint32_t highScore = GAME_getHighScore(&states[ST_GAME]);
    *DRAW_COLORS = 0x04;
    text("GAME OVER!", 40, 32);

    char* s = concatStringAndNumber("SCORE:", finalScore);
    int pos = (160 - (strLength(s) << 3)) >> 1;
    pos = pos < 0 ? 0 : pos;
    text(s, pos, 48);

    if((finalScore > highScore) || showBeatHighScore ){
        showBeatHighScore = 1;
        GAME_setHighScore(&states[ST_GAME], finalScore);
        text("A NEW HIGH SCORE!", 12, 64);
    }
    else{
        char* s = concatStringAndNumber("HIGH SCORE:", highScore);
        int pos = (160 - (strLength(s) << 3)) >> 1;
        pos = pos < 0 ? 0 : pos;        
        text(s, pos, 64);
    }
    text("PRESS ANY BUTTON", 16, 80);
    text("TO PLAY AGAIN!", 24, 88);
}

void GAMEOVER_start(PROGRAM_STATE *ps){
    ps;
    showBeatHighScore = 0;
}

void GAMEOVER_create(PROGRAM_STATE *state){
    state->start = GAMEOVER_start;
    state->update = GAMEOVER_update;
    state->draw = GAMEOVER_draw;
}
