#include "point.h"

void PT_Create(Point* p, int16_t x, int16_t y){
    p->x = x;
    p->y = y;
}

int PT_Equals(Point* p1, Point* p2){
    return (p1->x == p2->x) && (p1->y == p2->y);
}