#include "time.h"
#include "stdio.h"
/*
*  It's not necessary, but it's important for daily use
*/
int displayDateTime() 
{
    time_t currentTime;
    struct tm *localTime;
    char buffer[80];
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    strftime(buffer, sizeof(buffer), "Today's date: %Y-%m-%d\nCurrent time: %H:%M:%S", localTime);
    printf("%s\n", buffer);
}
