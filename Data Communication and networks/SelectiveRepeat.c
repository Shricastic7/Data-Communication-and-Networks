//
// Created by Prathamesh on 20-03-2022.
//

#include<stdio.h>
int frames[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
int nack[12] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

void sendFrames(int start, int end);
void retransmit(int start);
void getFrameNo(int no, int windowSize);

int main(){

    int windowSize = 0, ack, start = 0, win = 0;

    do{
        printf("\n Enter window size :");
        scanf("%d",&windowSize);
        if(windowSize < 2)
            printf("\n Enter window size greater than 1");
    }while(windowSize < 2);

    win += windowSize;
    sendFrames(start,win);

    while(win < 12){
        printf("\n Enter no of frames which you have received negative ack :");
        scanf("%d",&ack);
        if(ack == 0){
            start += (win-start);
            win += windowSize ;
            sendFrames(start,win);
        }else{
            printf("\n Retransmitting the frame..");
            getFrameNo(ack,windowSize);


            for(int i=windowSize;i>=0;i--){
                if(nack[i] != -1){
                    retransmit(nack[i]-1);
                }
            }
        }
    }

    printf("\n All frames transmitted successfully...!");

    return 0;
}


void retransmit(int index){
    printf("\n Frame %d is retransmitted..",frames[index]);
}

void sendFrames(int start, int end){

    for(int i=start;i<end;i++){
        printf("\n Frame %d is transmitted..",frames[i]);
    }
}

void getFrameNo(int no, int windowSize){
    int i=0;
    while(no > 0 && i < windowSize){
        int res = no%10;
        nack[i] = res;
        i++;
        no /= 10;
    }
}


