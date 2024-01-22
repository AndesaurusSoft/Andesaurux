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
