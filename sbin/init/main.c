#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
int main()
{
    puts("Launching the system...\n");
    pid_t pid = fork();
    srand(time(NULL));
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0)
    {
        // Child process
        execl("/usr/bin/minian/main.o", "init", (char *)NULL);
        pid = rand()%CLOCKS_PER_SEC+2;
        if (pid == 1)
        {
            fputs("execl", stderr);
        }
    }
    else
    {
        return 0;
    }
}
