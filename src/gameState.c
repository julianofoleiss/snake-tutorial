#include "gameState.h"
#include "programState.h"
#include "utils.h"

#include <stdio.h>

static const uint8_t fruitSprite[16] = { 0x00,0xa0,0x02,0x00,0x0e,0xf0,0x36,0x5c,0xd6,0x57,0xd5,0x57,0x35,0x5c,0x0f,0xf0};
static gameData_t gameStateData;

static void placeFruit(gameData_t *gd){
    PT_Create(&(gd->fruit), rnd(19), rnd(19));
}

static void reset(gameData_t *gd){
    gd->score = 0;
    SNK_Create(&gd->s);
    gd->frameCount = 0;
    gd->prevState = 0;
    placeFruit(gd);    
}

static void input(gameData_t *gd){
    uint8_t justPressed = *GAMEPAD1 & (*GAMEPAD1 ^ gd->prevState);
    if(justPressed & BUTTON_UP){
        SNK_Up(&(gd->s));
    }
    if(justPressed & BUTTON_DOWN){
        SNK_Down(&(gd->s));
    }    
    if(justPressed & BUTTON_LEFT){
        SNK_Left(&(gd->s));
    }      
    if(justPressed & BUTTON_RIGHT){
        SNK_Right(&(gd->s));
    }
    gd->prevState = *GAMEPAD1;
}

void GAME_start(PROGRAM_STATE *ps){
    reset(ps->stateData.game);
}

void GAME_update(PROGRAM_STATE *ps){
    gameData_t* gd = ps->stateData.game;
    gd->frameCount++;
    input(gd);
    if(gd->frameCount % 15 == 0){
        SNK_Update(&(gd->s));

        if(SNK_AteItself(&(gd->s))){
            reset(gd);
        }

        if(PT_Equals(&(gd->s.body[0]), &(gd->fruit))){
            SNK_Grow(&(gd->s));
            placeFruit(gd);
            gd->score+=100;
        }
    }
}

void GAME_draw(PROGRAM_STATE *ps){
    char scoreText[50];    
    gameData_t *gd = ps->stateData.game;

    SNK_Draw(&(gd->s));
    *DRAW_COLORS = 0x4320;
    blit(fruitSprite, gd->fruit.x * 8, gd->fruit.y * 8, 8, 8, BLIT_2BPP);

    // TODO: sprintf takes too much space. Rewrite this.
    sprintf(scoreText, "SCORE:%d", gd->score);
    
    *DRAW_COLORS = 0x04;
    text(scoreText, 0,0);
}

void GAME_create(PROGRAM_STATE *state){
    state->draw   = GAME_draw;
    state->start  = GAME_start;
    state->update = GAME_update;
    state->stateData.game = &gameStateData;
}


