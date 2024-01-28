#include <stdio.h>
main(argc, argv)
char **argv;
{
    for(;;)
    {
        puts(argv[1]);
    }
    return(0);
}