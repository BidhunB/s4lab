#include<stdio.h>
int main(){
    int i,j,bn,b[10],all[10],pn,p[10];
    for(i=0;i<10;i++){
        all[i]=-1;
    }
    printf("Enter the num of blocks :");
    scanf("%d",&bn);
    printf("Enter the size of blocks:\n");
    for(i=0;i<bn;i++){
        scanf("%d",&b[i]);
    }
    printf("Enter the num of process :");
    scanf("%d",&pn);
    printf("Enter the size of process:\n");
    for(i=0;i<pn;i++){
        scanf("%d",&p[i]);
    }
    //hero
    for(i=0;i<pn;i++){
        for(j=0;j<bn;j++){
            if(b[j]>=p[i]){
                all[i]=j;
                b[j]-=p[i];
                break;
            }
        }
    }
    //print
    printf("\nprocess_no\tProcess_size\tBlock_no\n");
    for(i=0;i<pn;i++){
        printf("%d\t\t%d\t\t",i+1,p[i]);
        if(all[i]!=-1){
            printf("%d",all[i]+1);
        }
        else{
            printf("NOT ALLOCATED !!");
        }
        printf("\n");

    }
    return 0;
}