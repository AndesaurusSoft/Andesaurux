/* Da heck? It's so hard, creating syscalls is easier than this */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int createtar(char *dest, char *file)
{
    FILE *f = fopen(dest, "w");
    FILE *f2 = fopen(files[1], "r");
    fprintf(f, "Name: %s\n", file);
    fprintf(f, "Size: %d\n", strlen(fopen(file, "r")));
    int c;
    while ((c = getc(f2)) != EOF)
    {
        putc(c, f);
    }
    fprintf(f, "\n");
    fclose(f);
}
int extract(char *dest, char *tarball)
{
    FILE *f = fopen(tarball, "r");
    mkdir(dest, 0777);
    int c;
    while ((c = getc(f)) != EOF)
    {
        /* */
    }
}
int main(int argc, char **argv)
{
    if (argc < 3)
    {
        puts("Not enough arguments\n");
    }
    else if (strcmp(argv[1], "-c") == 0)
    {
        for (int i = 2; i <= argc; i++)
        {
            createtar(argv[2], argv[i]);
        }
        puts("Done\n");
    }
    else if (strcmp(argv[1], "-x") == 0)
    {
        puts("Not done yet\n\007");
    }
    return (0);
}