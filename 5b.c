// consider the last 100 bytes as region . write a c program to check whether
// the region is locked or not , if teh region is lcoked print pid of the
// process which has locked , if the region is not locked lock the region with
// an exclusive lock . read the last 50 bytes and unlock the region
#include <errno.h>
#include <fcntl.h> //open
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
    int fd; // for opening file and store status
    char buffer[255];
    struct flock fvar;
    if (argc == 1)
    {
        printf("Provide file name\n");
        printf("usage %s filename\n", argv[0]);
        return -1;
    }

    fd = open(argv[1], O_RDWR); // read write mode
    if (fd == -1)
    {
        printf("Error : \n\n");
        perror("open");
        exit(1);
    }
    printf("fd = %d\n", fd);

    fvar.l_type = F_WRLCK;
    fvar.l_whence = SEEK_END;
    fvar.l_start = SEEK_END-100;
    fvar.l_len = 100;

    printf("Press enter to set lock ");
    getchar();
    printf("try to getlock .... \n");

    // if region already locked get pid of it
    if ((fcntl(fd, F_SETLK, &fvar)) == -1)
    {
        fcntl(fd, F_GETLK, &fvar);
        printf("\n File already locked by process pid = %d\n", fvar.l_pid);
        return -1;
    }

    printf("\nlocked\n");

    if ((lseek(fd, SEEK_END - 50, SEEK_END)) == -1)
    {
        perror("lseek");
        exit(1);
    }
    if ((read(fd, buffer, 100)) == -1)
    {
        perror("read");
        exit(1);
    }
    printf("data read fromFile ....\n");
    puts(buffer);

    printf("press enter to release lock\n");
    getchar();

    fvar.l_type = F_UNLCK;
    fvar.l_whence = SEEK_SET;
    fvar.l_start = 0;
    fvar.l_len = 0;

    if ((fcntl(fd, F_UNLCK, &fvar)) == -1)
    {
        perror("fcntl");
        exit(0);
    }

    printf("Unlocked\n");
    close(fd);
    return 0;
}
