#include <stdio.h>
main(argc, argv)
/* 3. Give */
char **argv;
{
    FILE *f = fopen(argv[1], "w");
    fclose(f);
    printf("File %s created\n", argv[1]);
    getchar();
    return(0);
}