#include "stdio.h"
#include "time.h"
/*
*   Copyright (C) 2024 Anatoliy6463
*/
typedef unsigned mode_t;
int fork();
int exit(timer);
int sleep(sec);
int mount(source, target, filesystemtype, mountflags, data);     
int execl(path, arg, ...);
int execle(path, arg, ...);
int execlp(file, arg, ...);
execvp(file, arg, ...);
execvpe(file, arg, ...);
execv(path, arg, ...);
mkdir(path, mode);
waitpid(pid, status, options);
panic(str);
idle();
chdir(path);
umount(path);
shutdown(args);
