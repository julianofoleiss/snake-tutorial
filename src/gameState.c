#include "gameState.h"
#include "programState.h"

void GAME_start(void){

}

void GAME_update(void){

}

void GAME_draw(void){

}

void GAME_create(PROGRAM_STATE *state){
    state->draw   = GAME_draw;
    state->start  = GAME_start;
    state->update = GAME_update;
}


