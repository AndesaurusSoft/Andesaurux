#include "string.h"
/*
*   Copyright (C) 2024 Anatoliy6463
*/
char* strcpy(char* dest, const char* src) 
{
        while (*src) {
                *dest++ = *src++;
        }
        *dest = '\0';
        return dest;
}
