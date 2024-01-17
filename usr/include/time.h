#ifndef _TIME_H_
#define _TIME_H_
#include "sizet.h"
typedef size_t time_t;
typedef time_t clock_t;
/*
*   Copyright (C) 2024 Anatoliy6463
*/
struct tm {
    int tm_sec;   // seconds after the minute (0 - 60)
    int tm_min;   // minutes after the hour (0 - 59)
    int tm_hour;  // hours since midnight (0 - 23)
    int tm_mday;  // day of the month (1 - 31)
    int tm_mon;   // months since January (0 - 11)
    int tm_year;  // years since 1900
    int tm_wday;  // days since Sunday (0 - 6)
    int tm_yday;  // days since January 1 (0 - 365)
    int tm_isdst; // Daylight Saving Time flag
};
unsigned long long int CLOCKS_PER_SEC = 1000000;
int displayDateTime();
time_t time(time_t *timer);
clock_t clock(void);
double difftime(time_t time1, time_t time0);
time_t mktime(struct tm *timeptr);
char *asctime(const struct tm *timeptr);
char *ctime(const time_t *timer);
struct tm *gmtime(const time_t *timer);
struct tm *localtime(const time_t *timer);
size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr);

#endif /* _TIME_H_ */
