#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// Ax is based on listis program
void deleten(char *);
void deleten(char *bar)
{
  bar[strlen(bar) - 1] = '\0';
}
int main(int argc, char **argv)
{
	if (argc < 2)
		{
			return (-1);
		}
  FILE *new = fopen(argv[1], "w");
  fclose(new);
  char ls[4096][4096] = {0};
  for (int i = 0; i < 256; i++)
    {
	    fgets(ls[i], 255, stdin);
	    if (strcmp(ls[i], "EOF\n") == 0)
	      {
	        ls[i][0] = '\0';
	        ls[i][1] = '\0';
	        ls[i][2] = '\0';
	        break;
	      }
    }
  if (argc < 2)
    {
      puts("Save file as:\t");
      char name[256];
      fgets(name, 255, stdin);
      deleten(name);
      FILE *f = fopen(name, "r+");
      for (int i = 0; i < 4096; i++)
        {
          fputs(ls[i], f);
        }
      fclose(f);
    }
  else
    {
      FILE *f = fopen(argv[1], "r+");
      for (int i = 0; i < 4096; i++)
			fputs(ls[i], f);
      fclose(f);
    }
  return (0);
}
