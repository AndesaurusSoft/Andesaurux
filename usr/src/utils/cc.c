#include <stdio.h>
#define NAME "Andesaurus C Compiler"
#define YEAR 2024
typedef char* string;
typedef long long lolong;
typedef unsigned long long ulolong;
typedef unsigned uint;
typedef unsigned long ulong;
typedef short bool;
int noinpufileseerr()
{
  fputs("Error: No input files!\n\007", stderr);
  return (-1);
}
