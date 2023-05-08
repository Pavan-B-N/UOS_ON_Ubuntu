//program to illusrtate the race condition
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
static void charattime(char *);
int main(int argc, char const *argv[])
{
    int pid=fork();
    if(pid<0){
        printf("fork error");
    }else if(pid==0){
        charattime("output from child\n");
    }else{
        charattime("output feom parent\n");
    }

    return 0;
}

static void charattime(char *str){
    char *ptr;
    int c;
    setbuf(stdout,NULL);

    for(ptr=str;(c=*ptr++)!=0;)
        putc(c,stdout);
}

