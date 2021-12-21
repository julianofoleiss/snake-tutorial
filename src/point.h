#pragma once

#include <stdint.h>

typedef struct Point{
    int16_t x;
    int16_t y;
} Point;

void PT_Create(Point* p, int16_t x, int16_t y);
int PT_Equals(Point* p1, Point* p2);