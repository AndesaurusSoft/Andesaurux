#include "stdio.h"
#include "time.h"
/*
*   Copyright (C) 2024 Anatoliy6463
*/
typedef unsigned int mode_t;
int fork();
int exit(time_t timer);
int sleep(time_t sec);
int mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data);     
int execl(const char *path, const char *arg, ...);
int execle(const char *path, const char *arg, ...);
int execlp(const char *file, const char *arg, ...);
int execvp(const char *file, const char *arg, ...);
int execvpe(const char *file, const char *arg, ...);
int execv(const char *path, const char *arg, ...);
int mkdir(const char *path, mode_t mode);
int waitpid(int pid, int *status, int options);
int panic(const char *str);
int idle(void);
int checkproprietary(const char *name);
int chdir(const char *path);
int umount(const char *path);
int shutdown(char *args);