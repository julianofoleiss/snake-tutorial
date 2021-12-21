#include "snake.h"
#include "wasm4.h"

void SNK_Create(Snake *s){
    PT_Create(&(s->direction), 1, 0);
    s->len = 3;
    PT_Create(&(s->body[0]), 11, 10);
    PT_Create(&(s->body[1]), 10, 10);
    PT_Create(&(s->body[2]), 9, 10);
}

void SNK_Draw(Snake *s){
    int16_t i;
    *DRAW_COLORS = 0x0043;
    for(i = 0; i < s->len; i++){
        rect(s->body[i].x * 8, s->body[i].y * 8, 8, 8);
    }
    *DRAW_COLORS = 0x0042;
    rect(s->body[0].x * 8, s->body[0].y * 8, 8, 8);
}

void SNK_Update(Snake *s){
    int16_t i;
    for(i = s->len-1; i > 0; i--){
        s->body[i] = s->body[i-1];
    }
    s->body[0].x = (s->body[0].x + s->direction.x) % 20;
    s->body[0].y = ((s->body[0].y + s->direction.y) % 19);
    if(s->body[0].x < 0){
        s->body[0].x = 19;
    }
    if(s->body[0].y < 1){
        s->body[0].y = 19;
    }
}

Point* SNK_Tail(Snake *s){
    return &(s->body[s->len-1]);
}

void SNK_Grow(Snake *s){
    if(s->len < SNAKE_MAX_LEN){
        Point* tail = SNK_Tail(s);     
        PT_Create(&(s->body[s->len]), tail->x, tail->y);
        s->len++;
    }
}

uint8_t SNK_AteItself(Snake *s){
    uint16_t i;
    for(i = 1; i < s->len; i++){
        if(PT_Equals(&(s->body[0]), &(s->body[i]))){
            return 1;
        }
    }
    return 0;
}

void SNK_Down(Snake *s){
    PT_Create(&(s->direction), 0, 1);
}

void SNK_Up(Snake *s){
    PT_Create(&(s->direction), 0, -1);
}

void SNK_Right(Snake *s){
    PT_Create(&(s->direction), 1, 0);
}

void SNK_Left(Snake *s){
    PT_Create(&(s->direction), -1, 0);
}
