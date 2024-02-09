#include <stdio.h>
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
      default:
	printf("%c - WTF?!", c);
	break;
    }
  putchar('\n');
  return (0);
}
