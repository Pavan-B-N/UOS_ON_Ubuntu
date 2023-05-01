//write a c/c++ program that outputs the contents of its environment list
#include<stdio.h>
int main(int argc,char *argv[],char *envp[]){
    for(int i=0;envp[i]!=NULL;i++){
        printf("%s\n",envp[i]);
    }
    return 0;
}
/*
* COMPUTERNAME=PAVAN-B-N
* HOMEPATH=\Users\LOKESH
* LOGONSERVER=\\PAVAN-B-N
* NUMBER_OF_PROCESSORS=4
* PROCESSOR_ARCHITECTURE=x86
* PROCESSOR_IDENTIFIER=Intel64 Family 6 Model 140 Stepping 1, GenuineIntel
* PROCESSOR_LEVEL=6
* ProgramData=C:\ProgramData
* ProgramFiles=C:\Program Files (x86)
* SystemRoot=C:\WINDOWS
* USERPROFILE=C:\Users\LOKESH
* LANG=en_US.UTF-8
* USER=pavan

*/
