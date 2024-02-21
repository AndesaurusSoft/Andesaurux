#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define SECRET "\106\125\103\113"
#include "hq9p.c"
#define true 1
#define false 0
#define _ ;
/*
* This is a shell for Andesaurux.
* Minian will be more lighweight than bash and i will write doc for it.
*
* Fun fact: this code is written entirely in GNU Emacs :D
*
* MiNIAN DEVELOPMENT IS STOPPED! PLEASE USE OTHER UNIX SHELLS LIKE tcsh OR bash
*/

/* Prototypes */
analise(char *, char **)_
loop(char *, char *, char **);
/*Analyser*/
analise(char *cmd, char **args)
  {
    if (strcmp(cmd, "cat") == 0)
      {
	execvp("cat", &args[0]);
      }
    else if (strcmp(cmd, "help") == 0)
      {
	    puts("cat\thelp\ttouch\thq9p\nls\tcd\texlite\n");
      }
    else if (strcmp(cmd, "echo") == 0)
      {
	execvp("echo", &args[0]);
      }
    else if (strcmp(cmd, "info") == 0)
      {
	puts("Minian v0.0.1\nCopyright (C) 2024 AnatoliyL\nMinian is free software\nMinian is a shell for UNIX-like OS like Andesaurux\n");
      }
    else if (strcmp(cmd, "touch") == 0)
      {
	puts("Creating the file...\n");
	if (fopen(args[0], "r") != NULL)
	  {
	    puts("File already exists\n");
	    perror("File already exists");
	  }
	else
	  {
	    creat(args[0], 077);
	    printf("File %s was successfuly created\n", args[0]);
	  }
      }
    else if (strcmp(cmd, "hq9p") == 0)
      {
	char *filename = args[0];
	hq9open(filename);
      }
    else if (strcmp(cmd, "f") == 0)
      {
	puts(SECRET);
      }
    else if (strcmp(cmd, "cd") == 0)
      {
	chdir(args[0]);
      }
    else if (strcmp(cmd, "ls") == 0)
      {
	if (args[0][0] == '\0')
	  args[0][0] = '.';
	execvp("ls", &args[0]);
      }
    else if (strcmp(cmd, "texor") == 0)
      {
	execvp("texor", &args[0]);
      }
    else if (strcmp(cmd, "exit") == 0)
      {
	exit(0);
      }
    else
      puts("Command not found!\nType \"Help\" for list of commands\n");
    return (0);
  }
/*I plan creating more commands, but that's all for today*/
loop(char *s, char *cmd, char **args)
{
  int argsstart = 0;
  puts("$\t");
  fgets(s, 1023, stdin);
  for (int i = 0; i < 256; i++)
    {
      if (s[0] != '\n')
        {
          char *token = strtok(s, " \n");
          if (token != NULL) 
            {
              strcpy(cmd, token);
              token = strtok(NULL, "\n");
              if (token != NULL) 
                {
                  strcpy(args[i], token);
                }
            }
          analise(cmd, args);
        }
    }
  putchar('\n');
}
main()
{
  char s[1024] = {0};
  char cmd[1024] = {0};
  char *args[1024] = {0};
  for (;;)
    loop(s, cmd, args);
  return (0);
}
