#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hq9p.c"
/*
* This is a shell for Andesaurux.
* Minian will be more lighweight than bash and i will write doc for it.
*/
/*
 * Fun fact: this code is written entirely in GNU Emacs :D
 */
/*Analyser*/
int analise(char *cmd, char *args)
  {
    if (strcmp(cmd, "cat") == 0)
      {
	FILE *f = fopen(args, "r");
	int c = NULL;
	while ((c = fgetc(f)) != EOF)
	  {
	    putchar(c);
	  }
	fclose(f);
      }
    else if (strcmp(cmd, "help") == 0)
      {
	if (strcmp(args, "--minian") == 0)
	  {
	    puts("Minian is a free shell made by Anatoliy6463 in 2024\nIt is protected by AFL\n");
	  }
	else if (strcmp(args, "--andesaurux") == 0)
	  {
	    puts("Andesaurux is a fully free OS made by Anatoliy6463 in 2024\nIt is protected by AFL\n");
	  }
	else if (strcmp(args, "--afl") == 0)
	  {
	    puts("AFL is short for Andesaurus Free License, it is a copyleft license\n");
	  }
	else
	  {
	    puts("cat\thelp\ttouch\thq9p\n");
	  }
      }
    else if (strcmp(cmd, "touch") == 0)
      {
	puts("Creating the file...\n");
	if (fopen(args, "r") != NULL)
	  {
	    puts("File already exists\n");
	    perror("File already exists");
	  }
	else
	  {
	    FILE *f = fopen(args, "w");
	    printf("File %s was successfuly created\n", args);
	    fclose(f);
	  }
      }
    else if (strcmp(cmd, "hq9p") == 0)
      {
	char *filename = args;
	open(filename);
      }
    else
      puts("Command not found!\n");
  }/*I plan creating more commands, but that's all for today*/
int main()
{
  /*This is test for minian commands*/
  char cmd[256];
  puts("Enter a command:\t");
  char args[256];
  fgets(cmd, 255, stdin);
  if ((strlen(cmd) > 0) && (cmd[strlen (cmd) - 1] == '\n'))
            cmd[strlen (cmd) - 1] = '\0';

  puts("Enter arguments for command:\t");
  fgets(args, 255, stdin);
  
  if ((strlen(args) > 0) && (args[strlen (args) - 1] == '\n'))
            args[strlen (args) - 1] = '\0';

  analise(cmd, args);
  return (0);
}
