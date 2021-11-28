// 11. Write a C programs that illustrate communication between two
//     unrelated processes using named pipe.
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
int main()
{
    int pfds[2];
    char buf[30];
    if (pipe(pfds) == -1)
    {
        perror("pipe");
        exit(1);
    }
    printf("writingtofiledescriptor#%d\n", pfds[1]);
    write(pfds[1], "test", 5);
    printf("readingfromfiledescriptor#%d\n", pfds[0]);
    read(pfds[0], buf, 5);
    printf("read\"%s\"\n", buf);
}