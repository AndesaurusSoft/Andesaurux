#include "include/unistd.h"
#include "include/stdlib.h"
#include "include/stdio.h"
/*
*  This is a test of fork() system call in Andesaurux
*/
int main()
{
        for (int i = 0; i < 3; i++)
        {
                int pid = fork();
                sleep(1);
                timespent++;
                printf("PID=%d, Happy Birthday %d!\n", pid, pid);
        }
        exit(0);
}
