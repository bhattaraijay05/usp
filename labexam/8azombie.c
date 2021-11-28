// 8.Write a C program to create a Zombie process.

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int pid_t, child_pid;
    child_pid = fork();
    if (child_pid > 0)
    {
        sleep(10);
    }
    else
    {
        exit(0);
    }
    return 0;
}
