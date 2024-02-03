#include "stdio.h"
#include "stdarg.h"
#include "unistd.h"
/*
*   Copyright (C) 2024 Anatoliy6463
*/
int printf(const char *format, ...)
{
        va_list args;
        va_start(args, format);
        __asm__("push %%fs\n\t"
                        "push %%ds\n\t"
                        "pop %%fs\n\t"
                        "pushl %0\n\t"
                        "pushl $format\n\t"
                        "pushl $args\n\t"
                        "call printf\n\t"
                        "addl $12,%%esp\n\t"
                        "popl %0\n\t"
                        "pop %%fs"
                        ::"r" (format):"ax","cx","dx");
        va_end(args);
}
int puts(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        putchar(str[i]);
        i++;
    }
    putchar('\n');
    return i;
}
int putchar(int c) {
    __asm__("mov $0x02, %%eax\n\t"
            "mov $0x01, %%ebx\n\t"
            "movb %0, %%dl\n\t"
            "int $0x80"
            ::"r" (c)
            :"%eax","%ebx","%edx");
}
int fputs(const char *str, FILE *f) {
    int i = 0;
    while (str[i] != '\0') {
        fputc(str[i], f);
        i++;
    }
}
int fputc(int c, FILE *f) {
    __asm__("mov $0x02, %%eax\n\t"
            "mov $0x01, %%ebx\n\t"
            "movb %0, %%dl\n\t"
            "int $0x80"
            ::"r" (c)
            :"%eax","%ebx","%edx");
}
int putc(int c)
{
        putchar(c);
}
int cat(const char *filename) 
{
    FILE *f = fopen(filename, "r");
    int c;
    while ((c = fgetc(f)) != EOF) 
    {
        putchar(c);    
    }
}