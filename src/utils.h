#pragma once

#include <stdint.h>

uint8_t rnd(uint8_t n);
int strLength(char* s);
char* itoa(int n, char*s);
void strConcat(char *dest, char* src, int destBufferSize);
char* concatStringAndNumber(char* str, uint32_t num);