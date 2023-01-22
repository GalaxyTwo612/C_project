#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void generateChar();
void counting();
void dataPrinting();
int biggestElement();
void fileWriteMatrix();

int forCount[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int main(){
    generateChar();
    counting();
    dataPrinting();

    int index = biggestElement();
    printf("\n\nIndex : %d\n\n", index);
    fileWriteMatrix();
    return 0;
}

void generateChar(){
    FILE *fptr;
    fptr = fopen("charCount.txt","w");
    srand(time(NULL));
    int i=0;
    while(i<1000){
        int data =rand()%123;
        if(data>96){
            fprintf(fptr,"%c",data);
            i++;
        }
    }
    fclose(fptr);
}

void counting(){
    FILE *fptr;
    fptr = fopen("charCount.txt","r");
    char c = fgetc(fptr);

    while (!feof(fptr)){
        int index = c - 97;
        forCount[index] = forCount[index]+1;
        c = fgetc(fptr);
    }
    fclose(fptr);
}

void dataPrinting(){
    int alpha=97;
    for(int i=0; i<26 ; i++){
        printf("Data from array %c : %d\n",alpha,forCount[i]);
        alpha++;
    }
}

int biggestElement(){
    int tempIndex = 0;
    for (int i = 0; i < 26; ++i) {
        if (forCount[tempIndex] < forCount[i]){
            tempIndex = forCount[i];
        }
    }
    return tempIndex;
}

void fileWriteMatrix(){
    FILE *fpr;
    int index = biggestElement();

    if ((fpr = fopen("data.txt","w")) == NULL){
        printf("File can't be opened!!");
        fclose(fpr);
        exit(1);
    } else{
        for (int i = 0; i < index; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (forCount[j]>=0){
                    fprintf(fpr, "%c   ",j+97);
                    forCount[j]--;
                } else{
                    fprintf(fpr, "%c%c%c%c",' ',' ', ' ', ' ');
                }
            }
            fprintf(fpr, "\n");
        }
        fclose(fpr);
    }
}