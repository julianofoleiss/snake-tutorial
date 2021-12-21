#pragma once

#include "programState.h"
#include "point.h"
#include "snake.h"
#include "wasm4.h"

typedef struct gameData_t{
    Snake s;
    uint32_t frameCount;
    uint8_t prevState;
    Point fruit;    
    uint32_t score;
    uint32_t highScore;
} gameData_t;

void GAME_create(PROGRAM_STATE *state);
uint32_t GAME_getScore(PROGRAM_STATE *ps);
uint32_t GAME_getHighScore(PROGRAM_STATE *ps);
void GAME_setHighScore(PROGRAM_STATE *ps, uint32_t score);