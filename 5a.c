// 5a.write a c program to create hard link and soft link and display the hard link count with other attributes of the created file within the sample code
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>//facilitate getting information about files attributes.

//argv[0]=./a.out
int main(int argc,char *argv[]){
    int l;//storing status of link creation

    //creating filestat structure from stat
    struct stat filestat;

    //link() to create hard link
    printf("Creating hard link for %s as %s\n",argv[1],argv[2]);
    l=link(argv[1],argv[2]);
    if(l==0){
        printf("Hard link created successfully\n");
    }else{
        printf("Failed to create hard link\n");
    }

    //symlink() to create softlink
    printf("\nCreating soft link for %s as %s\n",argv[3],argv[4]);
    int sl=symlink(argv[3],argv[4]);
    if(sl==0){
        printf("Soft link created successfully\n");
    }else{
        printf("Failed to create soft link\n");
    }

    //display the file attributes of the original file
    printf("\n\nOriginal file details :- \n\n");
    int result;
    result=stat(argv[1],&filestat);
    if(result!=0){
        printf("Error gettig file status");
        exit(1);
    }
    printf("file size is %ld bytes\n",filestat.st_size);
    printf("Number of hard links %ld\n",filestat.st_nlink);
    // inode - file system unique identifier
    printf("inode number is %ld\n",filestat.st_ino);
    // %o - unsigned octal integer number
    printf("File permissions %o\n",filestat.st_mode && 0777);///look && 0777
    printf("Owner User ID : %d\n",filestat.st_uid);
    printf("Owner group ID : %d\n",filestat.st_gid);


    //display the number of hardlinks for the created file
    printf("\n\n---------------------");
    printf("\n\nNew Hard Link file details :- \n\n");
    result=stat(argv[2],&filestat);
     if(result!=0){
        printf("Error gettig file status");
        exit(1);
    }
    printf("Number of hard links %ld\n",filestat.st_nlink);
    
    return 0;
}
/*
* link() that creates a new hard link to an existing file
* symlink() to create a soft link
* Both function link() and symlink() return 0 on success. If any error occurs, then -1 is returned.
*/
