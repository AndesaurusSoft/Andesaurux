#include "stdlib.h"
#include "unistd.h"
my_system(const char *command) 
{
    pid_t pid = fork();
    if (pid == -1) 
    {
        return -1;
    } 
    else if (pid == 0) 
    {
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);
        return 127;
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return status;
    }
}