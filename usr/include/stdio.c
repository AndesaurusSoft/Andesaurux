#include "string.h"
#include "sizet.h"
/*
*   Copyright (C) 2024 Anatoliy6463
*/
size_t strlen(const char* str) 
{
        size_t len = 0;
        while (str[len] != '\0') {
                len++;
        }
        return len;
}
char* strcpy(char* dest, const char* src) 
{
        while (*src) 
        {
                *dest++ = *src++;
        }
        *dest = '\0';
        return dest;
}
int strcmp(const char* str1, const char* str2) 
{
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}
char *strcat(char *dest, const char *src) 
{
    char *tmp = dest;
    while (*dest) 
    {
        dest++;
    }
    while (*src) 
    {
        *dest++ = *src++;
    }
    *dest = '\0';
    return tmp;
}