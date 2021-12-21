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
} gameData_t;

void GAME_create(PROGRAM_STATE *state);
