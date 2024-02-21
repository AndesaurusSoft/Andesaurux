#include <dirent.h>
#include <stdio.h>
#warning "CANCEL C23 AND PROTECT GCC FROM USING IT!"
ls(path, a, b)
char *path;
int a;
int b;
{
  struct dirent *d;
  DIR *dh = opendir(path);
  if (!dh)
    {
      perror("Directory doesn't exist\n");
    }
  else
    {
      while ((d = readdir(dh)) != NULL)
        {
                if (!a && d->d_name[0] == '.')
                        continue;
                printf("%s  ", d->d_name);
                if(b) printf("\n");
        }
    }
}
main(argc, argv)
int argc;
char **argv;
{
  ls(argv[1], 0, 0);
}