#include <stdio.h>
int k = 0;
void beer99()
{
	for (int beer = 99; beer > 1; --beer)
	{
		printf("%d bottles of beer on the wall, %d bottles of beer\n", beer, beer);
		printf("Take one down, pass it around, %d bottles of beer on the wall!\n", --beer);
	}
	puts("1 bottle of beer on the wall, 1 bottle of beer\nTake on down, pass it around, no more bottles of beer on the wall!\n");
	puts("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some, 99 bottles of beer on the wall\n");
}
int hq9p(char *source)
{
  for (int i = 0; i < sizeof(source); i++)
  {
	  switch(source[i])
	  {
		  case 'H':
			  puts("Hello, world!\n");
			  break;
		  case 'Q':
			  puts(source);
			  break;
		  case '9':
			  beer99();
			  break;
		  case '+':
		  	k = k + 1;
		  	break;
	  }
  }
  return (0);
}
