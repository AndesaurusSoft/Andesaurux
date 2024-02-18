#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void deleten(char *);
void deleten(char *bar)
{
  bar[strlen(bar) - 1] = '\0';
}
int main(int argc, char **argv)
{
  puts("\t\tListis\tCopyright (C) 2024 AnatoliyL\n");
  puts("This program comes with ABSOLUTELY NO WARRANTY\nThis is free software, and you are welcome to redistribute it under GNU GPL license conditions\n");
  for (int i = 0; i < 5; i++)
    putchar('\n');
  puts("To watch existing list, press 'o', to create new, press 'n'\n");
  int v = getchar();
  if (v == 'o')
    {
      FILE *f = fopen(argv[1], "r");
      if (!f)
        {
          puts("Error! The file doesn't exist or there was no argument\n");
          return (1);
        }
      else
        {
          char command[256] = "cat ";
	  strcat(command, argv[1]);
	  system(command);
	  putchar('\n');
        }
      return (0);
    }
  puts("What do you want to add to list?\n");
  char ls[256][256] = {0};
  getchar();
  for (int i = 0; i < 256; i++)
    {
	    puts("> ");
	    fgets(ls[i], 255, stdin);
	    if (strcmp(ls[i], "EOF\n") == 0)
	      {
	        ls[i][0] = '\0';
	        ls[i][1] = '\0';
	        ls[i][2] = '\0';
	        break;
	      }
    }
  puts("Name your list:\t");
  char name[256] = {0};
  fgets(name, 255, stdin);
  deleten(name);
  FILE *f = fopen(name, "w");
  for (int i = 0; i < 255; i++)
    {
      fputs(ls[i], f);
    }
  puts("To watch your list, type \'./main <name>\'");
  fclose(f);
  return (0);
}
