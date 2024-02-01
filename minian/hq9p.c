#include <stdio.h>
#include "hq9p.h"
int open(char *name)
{
  FILE *f = fopen(name, "r");
  char source[1024];
  fgets(source, 1023, f);
  hq9p(source);
}
