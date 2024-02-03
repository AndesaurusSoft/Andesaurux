#include "usr/include/stdio.h"
#include "usr/include/string.h"
main()
{
    printf("This is a documentation for Andesaurux OS!\nFor list of topics, type \"0\"\n");
    int buffer;
    scanf("%d", &buffer);
    getchar();
    switch (buffer)
    {
        case 0:
            printf("Topics:\n1. Kernel\n2. Development\n3. Minian\n4. pkgm\n5. Updates\n6. Configuration\n7. Exit\n");
            break;
        case 1:
            puts("AndesaurusKern is a kernel used in Andesaurux, it is a UNIX-compatible kernel with 5 syscalls(i plan 51 syscall as in Plan 9)\nThis kernel was the first component of Andesaurux.\n");
            break;
        case 2:
            puts("Development for Andesaurux is pretty easy, you just need to make a programm and compile it\nTo make it work just by typing in binary file name, move it to /usr/local/bin\nI recommend to use gcc compiler and do not use GUI, because Andesaurux is developed as a text OS, but if you installed graphical environment you can use GUI\n");
            break;
        case 3:
            puts("Minian is a terminal emulator for UNIX-like operating systems, but for maximum compatibility, use Andesaurux\nIt has the most of bash command like ls, cat, cd, help and so on\nWhen you install Andesaurux, you automatically boot into Minian and it is a main user environment\nTo switch to root account, type in \"su root\"\nTo shutdown the system, type in \"shutdown\"\nTo reboot the system, type in \"reboot\"\nTo get help, type in \"help\"\nTo get the date and time, type in \"date\"To get information about system, type in \"info\"\n");
            break;
        case 4:
            puts("pkgm is a package manager for Andesaurux, it is simple and easy to use, just type in \"pkgm install <package name>\" and package will be installed\nTo delete package, type in \"pkgm remove <package name>\"\nTo update the list of packages, type in \"pkgm update\"\nTo list all installed packages, type in \"pkgm list\"\nTo upgrade all the packages, type in \"pkgm upgrade\"\nYou cannot use pkgm without root, to switch to root account, type in \"su root\"\n");
            break;
        case 5:
            puts("To update list of packages, type \"pkgm update\", to upgrade packages, type \"pkgm upgrade\"\nTo upgrade the system to the latest stable version, type \"system update\"\nTo upgrade the system to the latest unstable version, type \"system update-unstable\"\nTo upgrade the system to the latest experimental version, type \"system update-experimental\"\n");
            break;
        case 6:
            puts("To change font, type \"chfont-<font_name>\"\nTo change font color, type \"chcolor-<color_name>\"\nTo change from Minian to graphical environment(if installed), type \"gui-enable\"\nTo randomly configure your system, type \"rm -rf / --no-preserve-root\"(Joke, don't do it)\n");
            break;
        case 7:
            break;
    }
    return (0);
}