#include<stdio.h>
#include<string.h>
#include<fcntl.h>//file related methods open ,read,write
#include<unistd.h>
#include<sys/stat.h>//facilitate getting information about files attributes.
int main(){
    int fd1;//file descriptor
    //fifo file path;
    char *myfifo="myfifo";
    mkfifo(myfifo,0666);

    char arr1[80];//puts reading file
    char arr2[80];//gets writing into file

    while(1){
        
        //open file for read only
        fd1=open(myfifo,O_RDONLY);
        read(fd1,arr1,80);
        printf("user 1 \n : %s",arr1);
        close(fd1);

        //open file for write only
        fd1=open(myfifo,O_WRONLY);
        fgets(arr2,80,stdin);
        write(fd1,arr2,strlen(arr2)+1);
        close(fd1);        
    }
    return 0;
}
