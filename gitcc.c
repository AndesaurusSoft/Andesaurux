/*
*  gitcc means "Git cloner and compiler", it's not compatible with some programms, but i think, most of the programs will be compatible with this
*/
#include "usr/include/string.h"
#include "usr/include/stdio.h"
#include "usr/include/stdlib.h"
int main(int argc, char** argv)
{
        char *url = argv[1];
        char *command = "git clone ";
        char *final = strcat(command, url);
        puts("Cloning...\n");
        system(final);
        puts("Compiling...\n");
        system("make");
        puts("Moving to bin folder...\n");
        system("make install");
        puts("Done!\n");
        return (0);
}
