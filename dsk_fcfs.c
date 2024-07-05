#include<stdio.h>
#include<math.h>
int main(){
    int n,arr[100],hd,tot;
    float avg;
    printf("enter the number of elements:\n");
    scanf("%d",&n);

    printf("enter the head position: ");
    scanf("%d",&hd);

    printf("enter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("The fcfs order is:\n");
    printf("%d",hd);

    for(int i=0;i<n;i++){
        printf("-->%d",arr[i]);
        tot+=abs(hd-arr[i]);
        hd=arr[i];

    }

    avg=tot/n;

    printf("\nTotal seek time : %d\n",tot);
    printf("avg seek time : %f\n",avg);


}
/*if(hd<(199-hd)){
        for(int i=k;i>=0;i--,p++){
            f[p]=a[i];
        }
        for(int i=k+1;i<n-1;i++,p++){
            f[p]=a[i];
        }
    }
    else{
        for(int i=k;i<n;i++,p++){
            f[p]=a[i];

        }
        for(int i=k-1;i>=0;i--,p++){
            f[p]=a[i];

        }
    }
    printf("The order is:\n");*/