// Write a C program that illustrates suspending and resuming processes using signals

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_alarm(int signo)
{
    printf("from sigalarm function");
}
int main()
{
    int n;
    if (signal(SIGALRM, sig_alarm) == SIG_ERR)
        printf("Signal error");
    alarm(5);
    for (n = 0; n <= 5; n++)
        printf("from for loop n=%d", n);
    printf("main program terminated");
}