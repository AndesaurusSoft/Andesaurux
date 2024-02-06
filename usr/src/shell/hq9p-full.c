#include "hq9p.c"
int main(int argc, char **argv)
{
  for (int i = 1; i <= argc; i++)
  open(argv[i]);
}
