#include <stdio.h>
#include <string.h>

void 
deleten(char *);
void
deleten(char *bar)
{
    bar[strlen(bar) - 1] = '\0';
}

int
main(int argc, char **argv)
{
    if (fopen(argv[1], "r") == NULL)
        {
            FILE *bin = fopen(argv[1], "w");
            fclose(bin);
        }
    FILE *f = fopen(argv[1], "w");
    for (int i = 0; i < 1024; i++)
    {
        for (int j = 0; j < 1024; j++)
        {
            fprintf(f, "\0");
        }
    }
    for (int i = 2; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
                {
                    fprintf(f, "%d\t", i * j);
                }
            fprintf(f, "\n");
        }
    int c;
    fclose(f);
    f = fopen(argv[1], "r");
    while ((c = fgetc(f)) != EOF)
        {
            putchar(c);
        }
    putchar('\n');
    fclose(f);
    return (0);
}