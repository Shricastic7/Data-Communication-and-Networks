#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int arr[20][20];
int frameCount,k;
int sendFrame[100];

int main(){

    char inputFrame[20];
    int frameLength[20];

    int i,j,k=0,temp = 0;

    printf("\n Enter the count of Frames :");
    scanf("%d",&frameCount);

    for(i=0;i<frameCount;i++){
        printf("\n Enter Frame %d :",i+1);
        scanf("%s",&inputFrame);
        frameLength[i] = strlen(inputFrame);
        for(j=0;j<strlen(inputFrame);j++){
            arr[i][j] = inputFrame[j] - '0';
        }

    }
    // adding counter to frame
     for(i=0;i<frameCount;i++){
        for(j=frameLength[i]+1;j>0;j--){
            arr[i][j] = arr[i][j-1];
        }

        arr[i][j] = frameLength[i]+1;

    }

    // creating frame to send
    for(i=0;i<frameCount;i++){
        for(j=0;j<=frameLength[i];j++){
            sendFrame[k] = arr[i][j];
            k++;
        }

    }

    printf("\n Frame to be Sended :");
    for(int i=0;i<k;i++){
        printf("%d",sendFrame[i]);
    }
    printf("\n");


    printf("\n ------------At Receiver Side--------------");

    int counter = arr[0];
    printf("\n");

    // printing frames
    for(i=0;i<frameCount;i++){
        printf("\n Frame %d :",i+1);
        for(j=1;j<=frameLength[i];j++){
          printf("%d",arr[i][j]);
        }
        printf("\n");

    }


    return 0;
}

