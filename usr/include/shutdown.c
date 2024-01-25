#include <unistd.h>
int shutdown(char *args)
{
    if (strcmp(args, "now") == 0)
    {
        puts("Shutting down...\n");
        puts("It is now save to power off\n");
        idle();
    }
    return 0;
}