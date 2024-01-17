#include "unistd.h"
int fork() 
{
    int pid;
    asm volatile 
    (
        "mov $2, %%eax\n\t"
        "int $0x80\n\t"
        "mov %%eax, %0"
        : "=r" (pid)
        :
        : "%eax"
    );
    return pid;
}
