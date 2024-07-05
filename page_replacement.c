#include<stdio.h>
int main(){
    int i,j,k,n,f,rs[50],m[5],c=0,pf;
    printf("enter the num of pages: ");
    scanf("%d",&n);
    printf("enter the num of frame: ");
    scanf("%d",&f);
    printf("enter the pages: ");
    for(i=0;i<n;i++)
    scanf("%d",&rs[i]);

    for(i=0;i<f;i++){
        m[i]=-1;
    }

    //core
    printf("Page replacement process is--\n");
    for(i=0;i<n;i++){
        for(k=0;k<f;k++){
            if(m[k]==rs[i])
            break;
        }

        if(k==f){
            m[c++]=rs[i];
            pf++;
        }

        for(j=0;j<f;j++){
            printf("\t%d",m[j]);
        }
            if (k==f){
            printf("\tpage fault no: %d",pf);}
            printf("\n");
            
            if(c==f){
                c=0;
            }
        
    }
    printf("\nThe number of page fault is: %d",pf);
return 0;
}