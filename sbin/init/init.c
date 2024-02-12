#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
main()
{
    puts("Launching the system...\n");
    pid_t pid = fork();
    srand(time(NULL));
    if (pid == -1)
    {
        puts("Fork failed\n");
        return -1;
    }
    else if (pid == 0)
    {
        /* Child process */
        execl("/sbin/daemons/testd.o", "init", (char *)NULL);
        pid = rand()%CLOCKS_PER_SEC+2;
        waitpid(pid, NULL, 0);
        if (pid == 1)
        {
	  puts("WTH HAPPENED?!\n");
	  return (-1);
        }
    }
    else
    {
        return 0;
    }
}
turn_off()
{
    puts("Turning off the system...\n");
    exit(0);
    return 0;
}
