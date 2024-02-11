#include <stdio.h>
int exponent(int a, int b)
{
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
  long long a, b, c = 0;
  puts("Enter two numbers:\t");
  scanf("%d %d", &a, &b);
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
            break;
      default:
	      printf("%c - WTF?!", c);
	      break;
      
    }
  putchar('\n');
  return (0);
}
