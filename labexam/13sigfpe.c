// o SIGFPE
#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <string.h>
jmp_buf fpe;
void handler(int signum)
{
    // Do stuff here then return to execution below
    longjmp(fpe, 1);
}
int main()
{
    volatile int i, j;
    for (i = 0; i < 10; i++)
    {
        // Call signal handler for SIGFPE
        struct sigaction act;
        struct sigaction oldact;
        memset(&act, 0, sizeof(act));
        act.sa_handler = handler;
        act.sa_flags = SA_NODEFER | SA_NOMASK;
        sigaction(SIGFPE, &act, &oldact);
        if (0 == setjmp(fpe))
        {
            j = i / 0;
            sigaction(SIGFPE, &oldact, &act);
        }
        else
        {
            printf("handling SIGFPE....\n");
            sigaction(SIGFPE, &oldact, &act);
            /* handle SIGFPE */
        }
    }
    printf("After for loop\n");
    return 0;
}