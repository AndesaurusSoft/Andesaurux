#include "string.h"
/*
*   Copyright (C) 2024 Anatoliy6463
*/
int strcmp(const char* str1, const char* str2) 
{
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}
