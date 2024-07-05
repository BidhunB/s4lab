#include<stdio.h>
#include<stdlib.h>
int mutex=1,empty=3,full=0,x=0;
int main(){
    int n;
    int wait(int);
    int signal(int);
    void producer();
    void consumer();

    printf("1.produce\n2.consume\n3.exit\n");
    while(1){
        printf("\nEnter your choice:\n");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            if((mutex==1)&&(empty!=0)){
                producer();
            }
            else{
                printf("buffer is full !!");

            }

            break;
        case 2:
            if((mutex==1)&&(full!=0)){
                consumer();
            }
            else{
                printf("Buffer is empty !!");
            }
            break;
        case 3 :
            printf("Exiting...");
            exit(0);
        
        default:
            break;
        }
    }
    return 0;
}
    int wait(int s){
        return(--s);
    }
    int signal(int s){
        return(++s);
    }

    void producer(){
        mutex=wait(mutex);
        full=signal(full);
        empty=wait(empty);
        x++;
        printf("producer produces an item: %d",x);
        mutex=signal(mutex);

    }
    void consumer(){
        mutex=wait(mutex);
        full=wait(full);
        empty=signal(empty);
        x--;
        printf("consumer consumes an item: %d",x);
        mutex=signal(mutex);

    }


