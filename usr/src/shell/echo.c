#include <stdio.h>
#warning "This code isn't compatible with C23"
main(argc, argv)
int argc;
char **argv;
{
  print("%s\n", argv[1]);
  return (0);
}
/* CANCEL C23 STANDARD!!! */
/* PROTECT GCC FROM USING C23! IT IS THE WORST C STANDARD! */