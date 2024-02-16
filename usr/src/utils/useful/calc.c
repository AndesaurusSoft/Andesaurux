#include <stdio.h>
int exponent(int a, int b)
{
      if (b == 0)
      {
            return (1);
      }
      int c = a;
      for (int i = 1; i < b; i++)
      {
            c = c*a;
      }
      return (c);
}
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
	printf("%d+%d=%d", a, b, a+b);
	break;
      case '-':
	printf("%d-%d=%d", a, b, a-b);
	break;
      case '*':
	printf("%d*%d=%d", a, b, a*b);
	break;
      case '/':
	printf("%d/%d=%d", a, b, a/b);
	break;
      case '^':
      printf("%d^%d=%d", a, b, exponent(a, b));
      default:
	printf("%c - WTF?!", c);
	break;
    }
  putchar('\n');
  return (0);
}
