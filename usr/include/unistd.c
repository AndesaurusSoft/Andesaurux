#include "stdio.h"
#include "unistd.h"
#include "stdarg.h"
#include "stdlib.h"
execl(path, arg, ...)
const char *path;
const char *arg;
{
    va_list args;
    va_start(args, arg);
    char *argv[10];
    argv[0] = (char *)arg;
    int i = 1;
    const char *nextArg;
    while ((nextArg = va_arg(args, const char *)) != NULL && i < 10)
    {
        argv[i] = (char *)nextArg;
        i++;
    }
    va_end(args);
    argv[i] = NULL;
    return execv(path, argv);
}
execv(path, argv)
const char *path;
const char **argv;
{
    int argc = 0;
    while (argv[argc] != NULL) {
        argc++;
    }

    char **new_argv = (char **)malloc((argc + 1) * sizeof(char *));
    if (new_argv == NULL) {
        return -1;
    }

    /* Copy the program path and arguments into the new array */
    for (int i = 0; i <= argc; i++) {
        new_argv[i] = argv[i];
    }

    /* Execute the new program */
    int result = execvp(path, new_argv);

    /* Free the memory allocated for the new arguments array */
    free(new_argv);

    return result;
}
execvp(path, argv)
const char *path;
const char *argv;
{
    // Count the number of arguments
    int argc = 0;
    while (argv[argc] != NULL) {
        argc++;
    }

    // Create a new array for the arguments including the program path
    char **new_argv = (char **)malloc((argc + 1) * sizeof(char *));
    if (new_argv == NULL) {
        return -1; // Return an error if memory allocation fails
    }

    // Copy the program path and arguments into the new array
    for (int i = 0; i <= argc; i++) {
        new_argv[i] = argv[i];
    }

    // Execute the new program
    int result = -1;
    if (path != NULL && *path != '\0' && new_argv[0] != NULL) {
        result = execv(path, new_argv);
    }

    // Free the memory allocated for the new arguments array
    free(new_argv);

    return result;
}

typedef struct 
{
    struct Header *ptr;
    unsigned size;
} Header;

int fork() 
{
    int pid;
    asm volatile 
    (
        "mov $2, %%eax\n\t"
        "int $0x80\n\t"
        "mov %%eax, %0"
        : "=r" (pid)
        :
        : "%eax"
    );
    return pid;
}

int mkdir(path, mode, pid) 
const char *path;
mode_t mode;
{
    asm volatile
    (
        "mov $4, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "mov %1, %%ecx\n\t"
        "mov %2, %%edx\n\t"
        "int $0x80\n\t"
        "mov %%eax, %3"
        : "=r" (pid)
        : "r" (path), "r" (mode), "r" (pid)
        : "%eax", "%ebx", "%ecx", "%edx"
    );
    return pid;
}
#define MAX 32767
halt()
{
  asm volatile
    (
     "int $0x80"
     "hlt"
    );
}
panic(s)
char *s;
{
    printf("Kernel panic: %s\n", s);
    halt();
}
int shutdown(char *args)
{
    if (strcmp(args, "now") == 0)
    {
        clear();
        puts("Shutting down...\n");
        puts("It is now save to power off\n");
        halt();
    }
    return 0;
}
int sleep(time_t seconds) 
{
    clock_t end_time = clock() + seconds * CLOCKS_PER_SEC;

    while (clock() < end_time) 
    {
        halt();
    }
}

int waitpid(int pid, int *status, int options)
{
    asm volatile
    (
        "mov $5, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "mov %1, %%ecx\n\t"
        "mov %2, %%edx\n\t"
        "int $0x80\n\t"
        "mov %%eax, %3"
        : "=r" (*status)
        : "r" (pid), "r" (options), "r" (status)
        : "%eax", "%ebx", "%ecx", "%edx"
    );
}
chdir(path)
char *path;
{
    asm volatile
    (
        "mov $6, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "int $0x80\n\t"
        "mov %%eax, %1"
        : "=r" (path)
        : "r" (path)
        : "%eax", "%ebx"
    );
}

int umount(path)
char *path;
{
    asm volatile
    (
        "mov $7, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "int $0x80\n\t"
        "mov %%eax, %1"
        : "=r" (path)
        : "r" (path)
        : "%eax", "%ebx"
    );
}

int rename(from, to)
char *from;
char *to;
{
    asm volatile
    (
        "mov $8, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "mov %1, %%ecx\n\t"
        "int $0x80\n\t"
        "mov %%eax, %2"
        : "=r" (to)
        : "r" (from), "r" (to)
        : "%eax", "%ebx", "%ecx"
    );
}

int close(fd)
FILE *fd;
{
    asm volatile
    (
        "mov $9, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "int $0x80\n\t"
        "mov %%eax, %1"
        : "=r" (fd)
        : "r" (fd)
        : "%eax", "%ebx"
    );
}

int creat(path, mode)
char *path;
mode_t mode;
{
    if (mode != 0777 || mode != 0666 || mode != 0333 || mode != 0222)
    {
        fprintf(stderr, "Mode must be 0777 or 0666 or 0333 or 0222\n");
        exit(1);
    }
    FILE *f = fopen(path, "w");
    fclose(f);
}

int mknod(path, mode, addr)
char *path;
mode_t mode;
mode_t addr;
{
    if (mode != 0777 || mode != 0666 || mode != 0333 || mode != 0222)
    {
        fprintf(stderr, "Mode must be 0777 or 0666 or 0333 or 0222\n");
        exit(1);
    }
    asm volatile
    (
        "mov $11, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "mov %1, %%ecx\n\t"
        "mov %2, %%edx\n\t"
        "int $0x80\n\t"
        "mov %%eax, %3"
        : "=r" (path)
        : "r" (path), "r" (mode), "r" (addr)
        : "%eax", "%ebx", "%ecx", "%edx"
    );
}

int close(fd)
FILE *fd;
{
    asm volatile
    (
        "mov $9, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "int $0x80\n\t"
        "mov %%eax, %1"
        : "=r" (fd)
        : "r" (fd)
        : "%eax", "%ebx"
    );
}

int read(fd, buffer, count)
FILE *fd;
char *buffer;
int count;
{
    fgets(buffer, count, fd);
}

int write(fd, buffer, count)
FILE *fd;
char *buffer;
int count;
{
    for (int i = 0; i < count; i++)
        fputc(buffer[i], fd);
}

int rename(from, to)
char *from;
char *to;
{
    FILE *o = fopen(from, "r");
    FILE *n = fopen(to, "w");
    int c;
    while ((c = fgetc(o)) != EOF)
        fputc(c, n);
    fclose(o);
    fclose(n);
    delete(from);
}

int del(path)
char *path;
{
    asm volatile
    (
        "mov $10, %%eax\n\t"
        "mov %0, %%ebx\n\t"
        "int $0x80\n\t"
        "mov %%eax, %1"
        : "=r" (path)
        : "r" (path)
        : "%eax", "%ebx"
    );
}

int clear()
{
    printf("\033[2J\033[1;1H");
}

int time()
{
    printf("%d", time(0));
}