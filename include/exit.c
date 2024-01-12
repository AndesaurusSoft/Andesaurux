#include "stdlib.h"
#include "time.h"
#include "unistd.h"
int exit(time_t timer)
{
    sleep(timer);
    asm volatile(
        "mov $1, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "int $0x80"
        :
        : "r" (timer)
        : "%eax", "%ebx"
    );
}
