#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//int id;
int main()
{
    int id;
    
    id = fork();
    printf("hello world \n");
    //id in the child process is always gonna be 0
    //id in the process is always gonna be different by 0, and is in the main
    //printf("hello world from id: %d \n", id);
    
    if(id == 0)
    {
        printf("hello, i'm child process id=%d, PID=%d \n", id, getpid());//ciao mondo dal processo figlio
    }
    else
    {
        printf("hello i'm the main process id=%d, PID=%d \n",id, getpid());//ciao mondo dal processo ID
    }

    return 0;
}