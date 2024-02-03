#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    printf("Hello, world!\n");
    fork();
    exit(0);
    return 0;
}