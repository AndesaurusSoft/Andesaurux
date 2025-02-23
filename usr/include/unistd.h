#include "stdio.h"
#include "time.h"
#include "sizet.h"
/*
*   Copyright (C) 2024 AnatoliyL
*/
typedef unsigned mode_t;
int fork();
int exit(value);
int sleep(sec);
int mount(source, target, filesystemtype, mountflags, data);     
int execl(path, arg, ...);
int execle(path, arg, ...);
int execlp(file, arg, ...);
int execvp(file, arg, ...);
int execvpe(file, arg, ...);
int execv(path, arg, ...);
int mkdir(path, mode);
int waitpid(pid, status, options);
int panic(str);
int idle();
int chdir(path);
int umount(path);
int shutdown(args);
int creat(path, mode);
int mknod(path, mode, addr);
int rename(from, to);
int close(fd);
int read(fd, buf, count);
int write(fd, buf, count);
int open(file, how, ...);
int del(path);
int clear();
int time();
int chroot(path);
int kill(pid, sig);
int rmdir(path);
int print(str);
int infiniteloop();
int oops(pid, fmt, num);
