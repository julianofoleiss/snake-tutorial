#pragma once

typedef struct PROGRAM_STATE{
    void (*update)(void);
    void (*start)(void);
    void (*draw)(void);
} PROGRAM_STATE;