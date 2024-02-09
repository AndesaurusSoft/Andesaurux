#include <stdio.h>
/* Calculator for Andesaurux operating system */
int main(void)
{
  double a, b = 0;
  short int c = 0;
  puts("Enter two numbers:\t");
  scanf("%lg %lg", &a, &b);
  puts("Enter operation symbol:\t");
  getchar();
  c = getchar();
  switch(c)
    {
      case '+':
	printf("%g+%g=%g", a, b, a+b);
	break;
      case '-':
	printf("%g-%g=%g", a, b, a-b);
	break;
      case '*':
	printf("%g*%g=%g", a, b, a*b);
	break;
      case '/':
	if (b == 0)
	  {
	    puts("YOU CANT DIVIDE BY ZERO!\n");
	    return (1);
	  }
	printf("%g/%g=%g", a, b, a/b);
	break;
      default:
	printf("%c - WTF?!", c);
	break;
    }
  putchar('\n');
  return (0);
}
