// 10. Write a program that illustrates how to execute two commands
//     concurrently with a command pipe.
#include <stdio.h>
#include <fcntl.h>
main()
{
    int pfd[2], p;
    pipe(pfd);
    p = fork();
    if (p == 0)
    {
        close(pfd[0]);
        close(1);
        dup(pfd[1]);
        execlp("ls", "ls", "-l", (char *)0);
    }
    else
    {
        close(pfd[1]);
        close(0);
        dup(pfd[0]);
        execlp("wc", "wc", (char *)0);
    }
}
