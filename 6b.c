#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void signalhandler(int);

int main(int argc, char const *argv[])
{
    signal(SIGINT,signalhandler);
    while (1)
    {
        printf("going to sleep for a second....\n");
        sleep(1);
    }
    return 0;
}

void signalhandler(int signum){
    printf("caught signal %d comming out \n",signum);
    exit(1);
}
