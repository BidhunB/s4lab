#include<stdio.h>
int main(){
    int n,m,i,k,j,alloc[20][20],max[20][20],avail[20],need[20][20];
    printf("Enter the num of processs: ");
    scanf("%d",&n);
    printf("Enter the num of resource: ");
    scanf("%d",&m);
    printf("Enter the allocation matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the max matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }

    printf("Enter the avaliable matrix:\n");
    for(i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    printf("Need matrix is :\n");
    for(i=0;i<n;i++){
        printf("\n");

        for(j=0;j<m;j++){
            printf("%d",need[i][j]);
        }
    }

    //pre hero
    int work[m],finish[n],s_s[n],count=0;
    for(i=0;i<m;i++){
        work[i]=avail[i];
    }
    for(i=0;i<n;i++){
        finish[i]=0;
    }

    //hero
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            if(finish[i]==0){
            int can_alloc=1;
            for(j=0;j<m;j++){
                if(need[i][j]>work[j]){
                    can_alloc=0;
                    break;
                }
            }
                if(can_alloc){
                    s_s[count++]=i;
                    for(int y=0;y<m;y++){
                        work[y]+=alloc[i][y];
                        
                    }
                    finish[i]=1;
                }
            }
        }
        
    }
    if (count==n){
        printf("The system is in safe sequence: \n");
        printf("The safe sequence is :\n");
        for(i=0;i<n;i++){
            printf("P%d",s_s[i]);
        }
        printf("\n");
}

       else{
    printf("system is  not  in safe state\n");//added
       }
       
        
    
    
    return 0;
    
}