// Write a program in C that illustrates how to execute two commands concurrently with a command pipe.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
    int pfds[2];
    char buf[30];
    if (pipe(pfds) == -1)
    {
        perror("pipe failed");
        exit(1);
    }
    if (!fork())
    {
        close(1);
        dup(pfds[1]);
        system("ls –l");
    }
    else
    {
        printf("parent reading from pipe \n");
        while (read(pfds[0], buf, 80))
            printf("%s \n", buf);
    }
}