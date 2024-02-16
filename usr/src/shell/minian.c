#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define SECRET "\0106\0125\0103\0113"
#include "hq9p.c"
/*
* This is a shell for Andesaurux.
* Minian will be more lighweight than bash and i will write doc for it.
*
* Fun fact: this code is written entirely in GNU Emacs :D
*/
/*Analyser*/
void ls (char *path, int a, int b);
int analise(char *cmd, char **args)
  {
    if (strcmp(cmd, "cat") == 0)
      {
	execvp("/usr/bin/cat", &args[0]);
      }
    else if (strcmp(cmd, "help") == 0)
      {
	if (strcmp(args[0], SECRET) == 0)
	  {
	    puts("What?\n");
	  }
	else
	  {
	    puts("cat\thelp\ttouch\thq9p\nls\tcd\texlite\n");
	  }
      }
    else if (strcmp(cmd, "echo") == 0)
      {
	execvp("/usr/bin/echo", &args[0]);
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
	    mknod(args[0], 077, 0);
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
	execvp("/usr/bin/ls", args[0]);
      }
    else if (strcmp(cmd, "exit") == 0)
      {
	exit(0);
      }
    else
      puts("Command not found!\nType \"Help\" for list of commands\n");
    return (0);
  }
void ls(char *path, int a, int b)
{
  struct dirent *d;
  DIR *dh = opendir(path);
  if (!dh)
    {
      perror("Directory doesn't exist\n");
    }
  else
    {
      while ((d = readdir(dh)) != NULL)
	{
		if (!a && d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
		if(b) printf("\n");
	}
    }
}
/*I plan creating more commands, but that's all for today*/
void loop(char *s, char *cmd, char **args)
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
int main()
{
  char s[1024] = {0};
  char cmd[1024] = {0};
  char *args[1024] = {0};
  for (;;)
    loop(s, cmd, args);
  return (0);
}
