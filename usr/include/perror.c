#include <stdio.h>
void perror(const char *str)
{
    fprintf(stderr, "%s\n", str);
    exit(1);
}