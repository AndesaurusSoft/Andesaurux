#include "stdio.h"
#include "unistd.h"
#include "stdarg.h"
#include "stdlib.h"
execl(const char *path, const char *arg, ...)
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
execv(const char *path, char *const argv[])
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
    int result = execvp(path, new_argv);

    // Free the memory allocated for the new arguments array
    free(new_argv);

    return result;
}
execvp(char *path, char *argv)
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
    struct Header *ptr; // Next block if on free list
    unsigned size; // Size of this block
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

int mkdir(const char *path, mode_t mode, int pid) 
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

int idle(void)
{
    while (1)
    {
        sleep(1);
    }
    return 0;
}

int panic(const char *str)
{
    printf("Kernel panic: %s\n", str);
    idle();
}

int shutdown(char *args)
{
    if (strcmp(args, "now") == 0)
    {
        puts("Shutting down...\n");
        puts("It is now save to power off\n");
        idle();
    }
    return 0;
}

int sleep(time_t seconds) 
{
    clock_t end_time = clock() + seconds * CLOCKS_PER_SEC;

    while (clock() < end_time) 
    {
        idle();
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
