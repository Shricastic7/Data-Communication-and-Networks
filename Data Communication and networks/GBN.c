#include<stdio.h>

int frames[10] = {1,2,3,4,5,6,7,8,9,10};

int main(){

    int windowSize=0, ack, start=0;

    do{
        printf("\n Enter window size :");
        scanf("%d",&windowSize);
        if(windowSize < 2)
            printf("\n Enter window size greater than 1");
    }while(windowSize < 2);

    send(0,windowSize);



    while(windowSize < 10){
        printf("\n Enter 1 if you got the 1st frame otherwise enter -1 :");
        scanf("%d",&ack);

        if(ack == -1){
            printf("\n Retransmitting the frames..");
            send(start,windowSize);
        }else{
            start++;
            windowSize++;
            send(start,windowSize);
        }

    }

    while(start < 10){
         printf("\n Enter 1 if you got the 1st frame otherwise enter -1 :");
        scanf("%d",&ack);
        if(ack == -1){
            printf("\n Retransmitting the frames..");
            sendSigle(start);
        }else{
            start++;
            sendSigle(start);
        }
    }

    printf("\n All frames transmitted successfully...!");
    return 0;
}

void sendSigle(int start){
    for(int i=start;i<10;i++){
        printf("\n Frame %d is transmitted..",frames[i]);
    }
}

void send(int start, int end){
    for(int i=start;i<end;i++){
        printf("\n Frame %d is transmitted..",frames[i]);
    }
}
