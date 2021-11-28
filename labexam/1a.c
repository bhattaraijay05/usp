// Write a C program that takes one or more file/directory names as command line
// input and reports the following information on the file:
// o File type
// o Number of links
// o Time of last access
// o Read, write, and execute permission

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
void main()
{
    int fd;
    struct stat buf;
    fd = open("f5.txt", O_RDONLY | O_CREAT, 600);
    if (fd != -1)
    {
        if (fstat(fd, &buf) == 0)
        {
            printf("mode of fileis %u", buf.st_mode);
            printf("\n size of the file is %u", buf.st_size);
            printf("\n device name %u", buf.st_dev);
            printf("\n inode of file is %u", buf.st_ino);
            printf("\n no. of links are %u", buf.st_nlink);
            printf("\n owner oof a file is %u", buf.st_uid);
            printf("\n no.of blocks is %u", buf.st_blocks);
            printf("\n group owner is %u", buf.st_gid);
            printf("\n blocks size of the file is %u", buf.st_blksize);
            printf("\n time of last modifiedis %u", buf.st_ctime);
        }
        else
            printf("error in fstat() syscall");
    }
    else
        printf("error in open() sys call");
}