#include <iostream>
#include <signal.h>
using namespace std;
int main()
{
    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGINT);
    sigaddset(&sigset, SIGUSR1);
    sigaddset(&sigset, SIGQUIT);
    sigaddset(&sigset, SIGALRM);
    sigaddset(&sigset, SIGFPE);
    sigaddset(&sigset, SIGSEGV);
    if (sigprocmask(SIG_SETMASK, &sigset, 0) == -1)
        perror("sigprocmask");
    if (sigprocmask(0, NULL, &sigset) < 0)
        perror("sigprocmaskerror");
    if (sigismember(&sigset, SIGINT))
        cout << "SIGINT" << endl;
    if (sigismember(&sigset, SIGFPE))
        cout << "SIGFPE" << endl;
    if (sigismember(&sigset, SIGQUIT))
        cout << "SIGQUIT" << endl;
    if (sigismember(&sigset, SIGUSR1))
        cout << "SIGUSR1" << endl;
    if (sigismember(&sigset, SIGUSR1))
        cout << "SIGUSR1" << endl;
    if (sigismember(&sigset, SIGALRM))
        cout << "SIGALRM" << endl;
    if (sigismember(&sigset, SIGSEGV))
        cout << "SIGSEGV" << endl;
    if (sigismember(&sigset, SIGTERM))
        cout << "SIGTERM" << endl;
}