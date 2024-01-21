#include <usr/include/stdio.h>
#include <usr/include/string.h>
#include <usr/include/time.h>
deleten();
deleten(const char *str) 
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
            for (int y = 0; i < 1000; i++)
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
    }
}