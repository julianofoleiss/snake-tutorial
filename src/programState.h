#pragma once

typedef struct gameData_t gameData_t;

typedef struct PROGRAM_STATE{
    void (*update)(struct PROGRAM_STATE*);
    void (*start)(struct PROGRAM_STATE*);
    void (*draw)(struct PROGRAM_STATE*);
    union {
        gameData_t* game;
    } stateData;
} PROGRAM_STATE;

void STATE_dummyStart(PROGRAM_STATE *ps);
void STATE_dummyUpdate(PROGRAM_STATE *ps);
void STATE_dummyDraw(PROGRAM_STATE *ps);