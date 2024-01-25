#include <unistd.h>
#include <stdio.h>
int panic(const char *str)
{
    printf("Kernel panic: %s\n", str);
    idle();
}