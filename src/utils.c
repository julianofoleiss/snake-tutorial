#include <stdint.h>
#include <stdlib.h>
#include "utils.h"

extern char stringText[50];
extern char numberText[20];

uint8_t rnd(uint8_t n){
    return rand() % n;
}

int strLength(char* s){
    int c = 0;
    while(*s != 0)
        s++, c++;
    return c;
}

static void reverse(char *s){
    int i, j, n;
    char c;
    n = strLength(s);
    for(i = 0, j = n-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

char* itoa(int num, char*s){
    int i = 0, sinal;
    sinal = num;
    if(num < 0)
        num = -num;
    do{
        s[i++] = num % 10 + '0';
    } while((num/=10) > 0);
    if(sinal < 0)
        s[i++] = '-';
    s[i] = 0;
    reverse(s);
    return s;
}

void strConcat(char *dest, char* src, int destBufferSize){
    int dest_n = strLength(dest);
    int src_n = strLength(src);
    if((dest_n + src_n + 1) > destBufferSize){
        src_n = destBufferSize - dest_n - 1;
    }
    int i;
    int k = 0;
    for(i = dest_n; i < (dest_n + src_n); i++)
        dest[i] = src[k++];
    dest[i] = 0;
}

char* concatStringAndNumber(char* str, uint32_t num){
    stringText[0] = 0;
    numberText[0] = 0;
    strConcat(stringText, str, 50);
    strConcat(stringText, itoa(num, numberText), 20);
    return stringText;
}