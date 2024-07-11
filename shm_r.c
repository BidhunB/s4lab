#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
int main(){
    void *s_m;
    int shmid;
    char buffer[100];

    shmid=shmget((key_t)1222,1024,0666|IPC_CREAT);
    printf("key of smemory is %d\n",shmid);
    s_m=shmat(shmid,NULL,0);
    printf("process attached at %p",s_m);

    strcpy(s_m,buffer);
    printf("data read is: %s\n",(char *)s_m);

    return 0;
}