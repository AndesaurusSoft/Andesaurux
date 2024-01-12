#include "include/unistd.h"
#include "include/stdlib.h"
#include "include/stdio.h"
#include "include/time.h"
/*
*  This is a test of fork() system call and displaydatetime() app in Andesaurux
*/
int main()
{
        for (int i = 0; i < 3; i++)
        {
                int pid = fork();
                sleep(1);
                printf("PID=%d, Happy Birthday %d!\n", pid, pid);
        }
        displayDateTime();
        exit(0);
}
