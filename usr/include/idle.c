#include <unistd.h>
int idle(void)
{
    while (1)
    {
        sleep(1);
    }
    return 0;
}