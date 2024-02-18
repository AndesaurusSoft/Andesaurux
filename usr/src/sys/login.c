/* Login system for Andesaurux OS */
/* Created on 18 February 2024 by AnatoliyL */
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    char username[128] = {0};
    char passwd[128] = {0};
    print("Username:\t", 15);
    fgets(username, 127, stdin);
    print("Password:\t", 15);
    fgets(passwd, 127, stdin);
    FILE *f = fopen("/etc/passwd", "r");
    char line[256] = {0};
    while (fgets(line, 255, f))
      {
        if (strstr(line, username) && strstr(line, passwd))
          {
            execvp("/bin/sh", username);
            break;
          }
        else if (strstr(line, username) && !strstr(line, passwd))
          {
            print("Wrong password\nTry again\n", 15);
            fgets(passwd, 127, stdin);
          }
        else
          {
            print("Wrong username\nTry again\n", 15);
            fgets(username, 127, stdin);
            fgets(passwd, 127, stdin);
          }
      }
    fclose(f);
    return 0;
}

/* I've done it very fast :D */