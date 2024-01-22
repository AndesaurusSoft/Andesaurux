#include <stdio.h>
main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "r");
    int c;
    while ((c = fgetc(f)) != EOF)
    {
        putchar(c);
    }
    return(0);
}