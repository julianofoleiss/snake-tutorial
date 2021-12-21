#pragma once

#include <stdint.h>
#include "point.h"
#define SNAKE_MAX_LEN 128

typedef struct Snake{
    Point body[SNAKE_MAX_LEN];
    uint16_t len;
    Point direction;
} Snake;

void SNK_Create(Snake *s);
void SNK_Draw(Snake *s);
void SNK_Update(Snake *s);
Point* SNK_Tail(Snake *s);
void SNK_Grow(Snake *s);
uint8_t SNK_AteItself(Snake *s);
void SNK_Down(Snake *s);
void SNK_Up(Snake *s);
void SNK_Left(Snake *s);
void SNK_Right(Snake *s);