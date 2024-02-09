#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
#define MIN 0
#define TIMES 100
int main(int argc, char **argv)
{
  int randnum = 0;
  puts("\t\tRandom numbers\n\t\tv0.0.1\n");
  srand(time(NULL));
  srand(rand()%MAX+MIN);
  for (int i = 0; i < TIMES; i++)
    {
      randnum = rand()%MAX+MIN;
      printf("%d", randnum);
    }
  puts("\n\n\n");
  return (0);
}
