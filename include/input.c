#include "stdio.h"
#include "stdarg.h"
/*
*   Copyright (C) 2024 Anatoliy6463
*/
int getchar(void) 
{
        int c;
        asm volatile(
                "mov $3, %%eax\n\t"
                "int $0x80\n\t"
                "mov %%eax, %0"
                : "=r" (c)
                :
                : "%eax"
        );
        return c;
}
int fgetc(FILE *f) 
{
    int c;
    asm volatile(
        "mov $3, %%eax\n\t"
        "mov %%ebx, %1\n\t"
        "int $0x80\n\t"
        "mov %%eax, %0"
        : "=r" (c)
        : "r" (f)
        : "%eax", "%ebx"
    );
    return c;
}
int scanf(const char *format, ...) 
{
        va_list args;
        va_start(args, format);
        __asm__("push %%fs\n\t"
                        "push %%ds\n\t"
                        "pop %%fs\n\t"
                        "pushl %0\n\t"
                        "pushl $format\n\t"
                        "pushl $args\n\t"
                        "call scanf\n\t"
                        "addl $12,%%esp\n\t"
                        "popl %0\n\t"
                        "pop %%fs"
                        ::"r" (format):"ax","cx","dx");
        va_end(args);
}
