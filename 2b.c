// orphan process is an computer process whose parent process has finished or terminated though it remains running itself
/*
p=frok()
p==0 -> child process
p>0 -> parent process
p<0 -> couldn't create child proces
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    int pid=fork();
    if(pid>0){
        printf("Parent process \n");
        printf("ID : %d \n",getpid());
    }else if(pid==0){
        printf("child process\n");
        printf("ID : %d\n",getpid());
        printf("Parent ID :%d \n",getppid());

        sleep(10);//child process go to sleep meanWhile parent process has been terminated

        printf("child process\n");
        printf("ID : %d\n",getpid());
        printf("Parent ID : %d\n",getppid());
    }else{
        printf("Failed to create a child process  ");
    }

    return 0;
}
