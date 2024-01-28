#include <stdio.h>
#include <string.h>
main(argc, argv)
char **argv;
{
    char name[512] = "man-pages/";
    strcat(name, argv[1]);
    strcat(name, ".txt");
    FILE *f = fopen(name, "r");
    if (!f)
    {
        puts("No such man page\n");
        return(0);
    }
    int c;
    while ((c = fgetc(f)) != EOF)
    {
        putchar(c);
    }
}