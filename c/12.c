// 12. Write a C program that illustrates suspending and resuming
//     processes using signals
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void alarms(int signo)
{
    printf("alarmfunction.signo=%d\n,", signo);
}
int main()
{
    if (signal(SIGALRM, alarms) == SIG_ERR)
        printf("Signalerror");
    alarm(5);
    for (int i = 0; i < 10; i++)
        printf("i=%d\n", i);
    printf("mainprogramterminated\n");
    return 0;
}