// program to avoid zombie process by forking twice
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
int main()
{
    int pid;
    pid = fork(); // first child
    if (pid == 0)
    {
        pid = fork(); // second child
        if (pid == 0)
        {
            sleep(1);
            printf("second child parent id is %d\n", getppid());
        }
    }
    else
    {
        // parent process
        wait(NULL);
        sleep(2);
        system("ps -o pid,ppid,state,tty,command");
    }
    return 0;
}
