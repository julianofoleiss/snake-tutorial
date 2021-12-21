#include "wasm4.h"
#include "snake.h"
#include "point.h"
#include <stdlib.h>
#include <stdio.h>

// Próximo passo: Placing the fruit. https://wasm4.org/docs/tutorials/snake/placing-the-fruit

const uint8_t smiley[] = {
    0b11000011,
    0b10000001,
    0b00100100,
    0b00100100,
    0b00000000,
    0b00100100,
    0b10011001,
    0b11000011,
};

Snake s;
uint32_t frameCount;
uint8_t prevState;
Point fruit;
const uint8_t fruitSprite[16] = { 0x00,0xa0,0x02,0x00,0x0e,0xf0,0x36,0x5c,0xd6,0x57,0xd5,0x57,0x35,0x5c,0x0f,0xf0};
uint32_t score;

uint8_t rnd(uint8_t n){
    return rand() % n;
}

void placeFruit(){
    PT_Create(&fruit, rnd(19), rnd(19));
}

void reset(){
    score = 0;
    SNK_Create(&s);
    frameCount = 0;
    prevState = 0;
    placeFruit();    
}

void input(){
    uint8_t justPressed = *GAMEPAD1 & (*GAMEPAD1 ^ prevState);
    if(justPressed & BUTTON_UP){
        SNK_Up(&s);
    }
    if(justPressed & BUTTON_DOWN){
        SNK_Down(&s);
    }    
    if(justPressed & BUTTON_LEFT){
        SNK_Left(&s);
    }      
    if(justPressed & BUTTON_RIGHT){
        SNK_Right(&s);
    }
    prevState = *GAMEPAD1;
}

void start() {
    PALETTE[0] = 0xFBF7F3;
    PALETTE[1] = 0xE5B083;
    PALETTE[2] = 0x426E5D;
    PALETTE[3] = 0x20283D;

    reset();
}

void update () {
    char scoreText[50];
    frameCount++;
    input();
    if(frameCount % 15 == 0){
        SNK_Update(&s);

        if(SNK_AteItself(&s)){
            reset();
        }

        if(PT_Equals(&s.body[0], &fruit)){
            SNK_Grow(&s);
            placeFruit();
            score+=100;
        }
    }
    SNK_Draw(&s);
    *DRAW_COLORS = 0x4320;
    blit(fruitSprite, fruit.x * 8, fruit.y * 8, 8, 8, BLIT_2BPP);

    // TODO: sprintf takes too much space. Rewrite this.
    sprintf(scoreText, "SCORE:%d", score);
    
    *DRAW_COLORS = 0x04;
    text(scoreText, 0,0);
}
