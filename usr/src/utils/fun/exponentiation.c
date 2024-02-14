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
int main()
{
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            printf("%d^%d = %d\n", i, j, exponent(i, j));
        }
    }
}