// 5. Write a C program to list for every file in a directory, its inode number and file
// name.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char d[50];
    if (argc == 2)
    {
        bzero(d, sizeof(d));
        strcat(d, "ls ");
        strcat(d, "-i ");
        strcat(d, argv[1]);
        system(d);
    }
    else
        printf("\nInvalid No. of inputs");
}