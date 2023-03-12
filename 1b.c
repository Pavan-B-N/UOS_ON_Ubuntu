#include<stdio.h>
#include<stdlib.h>
int main(){
	char cmd[50];
	printf("Enter the unix shell command :");
	//fgets(char *str, int n, FILE *stream)
	fgets(cmd,50,stdin);
	system(cmd);
	return 0;

}
