#include<stdio.h>
#include<string.h>


char data[100]={0};
int counter=0;
int main(){

    printf("\n Enter data Frame :");
    scanf("%s",&data);

    stuff();
    printf("\n -------After Stuffing the Bits---------");
    printf("\n Stuffed :%s",data);
    unStuff();
     printf("\n\n -------After Removing the stuffed the Bits---------");
    printf("\n DeStuffed :%s\n",data);

    return 0;
}

void stuff(){
     for(int i=1;i<strlen(data);i++){
        if(data[i-1] == '1' && data[i] == '1'){
            counter++;
        }else{
            counter = 0;
        }
        if(counter == 5){
            shiftElements(i,1);
            counter=0;
        }
    }
}


void unStuff(){
    int count=0;
   for(int i=1  ;i<strlen(data);i++){
        if(data[i-1] == '1' && data[i] == '1'){
            count++;
        }else{
            count = 0;
        }
        if(count == 4){

            shiftElements(i+1,0);
            count=0;
        }
    }
}

void shiftElements(int index, int isRight){
    int j=0;
    if(isRight == 1){
        for(j=strlen(data)+1;j>index;j--){
        data[j] = data[j-1];
        }
        data[j] = '0';
    }else{
       for(j=index;j<strlen(data);j++){
            data[j] = data[j+1];
        }
    }
}
