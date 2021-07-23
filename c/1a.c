#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char *error_msg[] = {
    "\nUsage: ./12filestat <file|dir> [<file|dir>]\n\n", "\nFile does not exist !!\n\n ", "\nError doing 'stat' on file\n\n "};
void print_error(int msg_num, int exit_code, int exit_flag);
int main(int argc, char *argv[])
{
    int i;
    mode_t file_perm;
    struct stat file_details;
    char success_msg[] = "\nCommand executed successfully\n\n";
    if (argc < 2)
        print_error(0, 2, 1);
    for (i = 1; i < argc; i++)
    {
        printf("\n%s\n%s\n%s\n", "----------------", argv[i], "----------------");
        if (access(argv[i], F_OK) == -1)
        {
            print_error(1, 3, 0);
            continue;
        }
        if (lstat(argv[i], &file_details) < 0)
        {
            print_error(2, 4, 0);
            continue;
        }
        if (S_ISREG(file_details.st_mode))
            printf("File type : Regular\n");
        else if (S_ISDIR(file_details.st_mode))
            printf("File type : Directory\n");
        else if (S_ISLNK(file_details.st_mode))
            printf("File type : Symbolic link\n");
        else
            printf("File type : Other");
        printf("Number of links : %d\n", (int)file_details.st_nlink);
        printf("Time of last access : %s", ctime(&file_details.st_atime));
        printf("File Permissions:\n");
        file_perm = file_details.st_mode & ~S_IFMT;
        printf("\tUser : ");
        if (file_perm & S_IRUSR)
            printf("Readable, ");
        else
            printf("Not readable, ");
        if (file_perm & S_IWUSR)
            printf("Writable, ");
        else
            printf("Not writable, ");
        if (file_perm & S_IXUSR)
            printf("Executable\n");
        else
            printf("Not executable\n");
        printf("\tGroup : ");
        if (file_perm & S_IRGRP)
            printf("Readable, ");
        else
            printf("Not readable, ");
        if (file_perm & S_IWGRP)
            printf("Writable, ");
        else
            printf("Not writable, ");
        if (file_perm & S_IXGRP)
            printf("Executable\n");
        else
            printf("Not executable\n");
        printf("\tOthers : ");
        if (file_perm & S_IROTH)
            printf("Readable, ");
        else
            printf("Not readable, ");
        if (file_perm & S_IWOTH)
            printf("Writable, ");
        else
            printf("Not writable, ");
        if (file_perm & S_IXOTH)
            printf("Executable\n");
        else
            printf("Not executable\n");
    }
    printf("%s", success_msg);
    return 1;
}
void print_error(int error_index, int exit_code, int exit_flag)
{
    fprintf(stderr, "%s\n", error_msg[error_index]);
    if (exit_flag)
        exit(exit_code);
}