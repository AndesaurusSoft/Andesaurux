#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <dirent.h>
deleten();
displayDateTime();
ls(const char *directory);
displayDateTime() 
{
    time_t currentTime;
    struct tm *localTime;
    char buffer[80];
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    strftime(buffer, sizeof(buffer), "Today's date: %Y-%m-%d\nCurrent time: %H:%M:%S", localTime);
    printf("%s\n", buffer);
}
ls(const char *directory) 
{
    DIR *dir;
    struct dirent *entry;
    dir = opendir(directory);
    if (dir == NULL) 
    { 
        printf("Error opening directory\n");
        return;
    }
    while ((entry = readdir(dir)) != NULL) 
    {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}
deleten(char *str) 
{
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') 
    {
        str[len-1] = '\0';
    }
}
main()
{
    char buffer[1024];
    char currentdir[1024] = "~/Andesaurux/home";
    for (;;)
    {
        printf("$ ");
        fgets(buffer, 1024, stdin);
        deleten(buffer);
        if (strcmp(buffer, "exit") == 0)
        {
            exit(0);
        }
        else if (strcmp(buffer, "clear") == 0)
        {
            for (int y = 0; y < 1000; y++)
            {
                for (int x = 0; x < 1000; x++)
                {
                    printf(" ");
                }
            }
            getchar();
        }
        else if (strcmp(buffer, "help") == 0)
        {
            puts("exit\tclear\nhelp\tdate\n");
            getchar();
        }
        else if (strcmp(buffer, "date") == 0)
        {
            displayDateTime();
        }
        else if (strcmp(buffer, "ls") == 0)
        {
            ls(currentdir);         
        }
        else if (strcmp(buffer, "create_file") == 0)
        {
            char filename[1024];
            printf("Enter filename: ");
            fgets(filename, 1024, stdin);
            deleten(filename);
            FILE *f = fopen(filename, "w");
            fclose(f);
        }
        else if (strcmp(buffer, "app_launcher") == 0)
        {
            char filename[1024];
            printf("Enter filename: ");
            fgets(filename, 1024, stdin);
            deleten(filename);
            system(filename);
        }
        else
        {
            fprintf(stderr, "%s, command not found\n\007", buffer);
        }
    }
}