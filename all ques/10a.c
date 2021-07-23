// Write a C program that illustrates suspending and resuming processes using signals

// #include <stdio.h>
// #include <ospace/unix.h>

// int child_function()
// {
//     while (true) // Loop forever.
//     {
//         printf("Child loop\n");
//         os_this_process::sleep(1);
//     }
//     return 0; // Will never execute.
// }
// int main()
// {
//     os_unix_toolkit initialize;
//     os_process child(child function); // Spawn child.
//     os_this_process::sleep(4);
//     printf("child.suspend()\n");
//     child.suspend();
//     printf("Parent sleeps for 4 seconds\n");
//     os_this_process::sleep(4);
//     printf("child.resume()");
//     child.resume();
//     os_this_process::sleep(4);
//     printf("child.terminate()");
//     child.terminate();
//     printf("Parent finished");
//     return 0;
// }

#include <stdio.h>
#include <signal.h>

void sig_handler(int signum)
{

    printf("Inside handler function\n");
}

int main()
{
    int n;
    if (signal(SIGALRM, sig_handler) == SIG_ERR)
        printf("Signal error");
    alarm(5);
    for (n = 0; n <= 15; n++)
        printf("from for loop n=%d", n);
    printf("main program terminated");
}
void sig_alarm(int signo)
{
    printf("from sigalarm function");
}