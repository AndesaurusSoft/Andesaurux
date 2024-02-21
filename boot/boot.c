#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("Andesaurux v0.0.1 is booting...\n");
    execvp("/sbin/daemons/init", "root");
    return 0;
}