#include <stdio.h>
#include <string.h>
int change(int a, int b)
{
  a = b;
}
int main(int argc, char **argv)
{
  int c;
  if (argc < 3)
    {
      puts("NOT ENOUGH ARGUMENTS, SYSTEM HALTED!\n");
      return (-1);
    }
  for (int i = 0; i < strlen(argv[1]); i++)
    {
      if (argv[1][i] == argv[2][0])
	{
	  if (strcmp(argv[4], "yes") == 0 && argc > 4)
	    {
	      argv[1][i] = argv[3][0];
	    }
	  else
	    {
	      printf("%c-%c-%c found, would you like to change it to %c[Y/n]?\n", argv[1][i-1], argv[1][i], argv[1][i+1], argv[3][0]);
	      c = getchar();
	      if (c == 'Y' || c == 'y')
	        argv[1][i] = argv[3][0];
	    }
	}
    }
  puts(argv[1]);
  return (0);
}
