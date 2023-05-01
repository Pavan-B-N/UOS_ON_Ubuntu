/*
zombie is a process that has completed execution (via the exit system call) but still has an entry in the process table
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int pid=fork();
    if(pid<0){
        printf("Fork Error\n");
    }else if(pid==0){
        printf("child process exited\n");
        printf("cid %d",getpid());
        exit(0);
    }

    sleep(2);
    system("ps -o pid,ppid,state,tty,command");
    exit(0);

    return 0;
}
