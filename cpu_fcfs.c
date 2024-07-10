#include<stdio.h>
struct pro{
    int pno,arrtime,exetime,wtime,ctime,tatime;
}p[100],t;

void sort(int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].arrtime>p[j+1].arrtime){
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }

    }
}

void display(int n){
    int i=0;
    printf("process no\tarrtime\texetime\twtime\tctime\ttatime\n");
    
    for(i=0;i<n;i++){
        if(i==0){
            p[i].wtime=0;
        }
        else{
            p[i].wtime=p[i-1].ctime-p[i].arrtime;
            if(p[i].wtime<0){
                p[i].wtime=0;
            }
        }
    p[i].ctime=p[i].arrtime+p[i].exetime+p[i].wtime;
    p[i].tatime=p[i].exetime+p[i].wtime;
    printf("%d\t",p[i].pno);
    printf("%d\t",p[i].arrtime);
    printf("%d\t",p[i].exetime);
    printf("%d\t",p[i].wtime);
    printf("%d\t",p[i].ctime);
    printf("%d\n",p[i].tatime);
        
    }
}

int main(){
    int n,i,j=0;
    printf("\nEnter the number of process :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        j++;
        p[i].pno=j;
        printf("\nprocess No: %d",j);
        printf("\nArrival time:");
        scanf("%d",&p[i].arrtime);
        printf("\nExecution time :");
        scanf("%d",&p[i].exetime);
    }
    sort(n);
    display(n);
return 0;
}