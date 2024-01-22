#include "stdio.h"
#include "time.h"
/*
*   Copyright (C) 2024 Anatoliy6463
*/
int fork();
int exit(time_t timer);
int sleep(time_t sec);
int cat(const char *filename);
int mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data);     
int execl(const char *path, const char *arg, ...);