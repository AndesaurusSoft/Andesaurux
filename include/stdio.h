#ifndef STDIO_H
#define STDIO_H
/*
*   Copyright (C) 2024 Anatoliy6463
*/
#define NULL 0
struct __sFile 
{
        int unused; 
}; 
#define EOF     (-1)
typedef struct __sFILE FILE;
extern int printf(const char *format, ...);
extern int printk(const char *s, ...);
extern int puts(const char *str);
extern int scanf(const char *format, ...);
extern int sscanf(const char *str, const char *format, ...);
extern int fscanf(FILE *f, const char *str, ...);
extern int fputs(const char *str, FILE *f);
extern int fputc(int c, FILE *f);
extern int getchar(void);
extern int putchar(int c);
extern int fgetc(FILE *f);
extern int putc(int c);
extern int fclose(FILE *f);
extern FILE *fopen(const char *filename, const char *mode);
extern int fflush(FILE *f);
#endif // STDIO_H
