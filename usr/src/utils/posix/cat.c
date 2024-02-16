#include <stdio.h>
main(argc, argv)
char **argv;
{
  if (argc < 4)
  {
    int c;
    FILE *f;
    f = fopen(argv[1], "r");
    if (!f)
      {
        puts("Error! No such file!\n");
        return (0);
      }
    while ((c = getc(f)) != EOF)
     {
       putchar(c);
     }
    fclose(f);
    c = 0;
    putchar('\n');
  }
  else if (argv[2][0] == '>' && argc == 4)
  {
    int c;
    FILE *f;
    f = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "w");
    if (!f)
      {
        puts("Error! No such file!\n");
        return (0);
      }
    if (!f2)
      {
        puts("Error! No such file!\n");
        return (0);
      }
    while ((c = getc(f)) != EOF)
     {
        putc(c, f2);
     }
    fclose(f);
    fclose(f2);
    c = 0;
    putchar('\n');
  }
  return (0);
}