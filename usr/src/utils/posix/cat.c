#include <stdio.h>
int main(int argc, char **argv)
{
  int c;
  FILE *f;
  f = fopen(argv[1], "r");
  if (!f)
    {
      puts("Error! No such file!\n");
      return (0);
    }
  while (c != EOF)
    {
      c = getc(f);
      putchar(c);
    }
  fclose(f);
  c = 0;
  putchar('\n');
  return (0);
}
