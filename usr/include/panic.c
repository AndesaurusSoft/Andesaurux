#include "unistd.h"
#include "stdio.h"
int panic(fmt)
char *fmt;
{
    printf("Kernel panic: %s\nSYSTEM IS HALTED!\nALL UNSAVED DATA IS LOST!\nRESTART THE COMPUTER!\n", fmt);
    kill(1, 0);
    halt();
}