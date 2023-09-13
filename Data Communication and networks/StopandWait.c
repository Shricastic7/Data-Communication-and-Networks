#include<stdio.h>

int sendFrame[10] = {1,2,3,4,5,6,7,8,9,10};
int recieveFrame[10] = {0,1,0,1,0,0,1,0,1,0};

int main(){

    int i=0;

    while(i < 10){
        if(send(i) == 0){
            printf("\n Frame %d's ack received successfully...\n",sendFrame[i]);

            i++;
        }else{
            printf("\n Ack is not received...\n Sending frame again\n");
            recieveFrame[i] = 0;
        }
    }

    return 0;
}

int send(int frame){
    printf("\nSending frame %d",sendFrame[frame]);
    return recieve(frame);
}

int recieve(int frameIndex){
    sleep(3);
    if(recieveFrame[frameIndex] == 0){
        return 0;
    }
    return -1;
}
