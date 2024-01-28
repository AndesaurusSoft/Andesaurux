#include <stdio.h>
main(argc, argv)
char **argv;
{
    FILE *f = fopen(argv[1], "r");
    int c;
    do 
    {
        putchar(c);
        c = fgetc(f);
    } while(c != EOF);
    putchar('\n');
    fclose(f);
    return(0);
}