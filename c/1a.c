
// Write a C program that takes one or more file/directory names as command line
// input and reports the following information on the file:
// o File type
// o Number of links
// o Time of last access
// o Read, write, and execute permission

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int f;
    struct stat buf;
    f = open("a.txt", O_RDONLY);
    if (f != -1)
    {
        if (fstat(f, &buf) == 0)
        {
            printf("File type: ");
            if (S_ISREG(buf.st_mode))
                printf("regular file\n");
            printf("%lu\n", buf.st_nlink);
            printf("%lu\n", buf.st_atime);
            if (buf.st_mode & S_IRUSR)
            {
                printf("Read\n");
            }
            if (buf.st_mode & S_IWUSR)
            {
                printf("Write\n");
            }
            if (buf.st_mode & S_IXUSR)
            {
                printf("Execute\n");
            }
        }
    }
}