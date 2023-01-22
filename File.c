#include "stdio.h"
#include "stdlib.h"

// Integer
int main(){
    FILE * fpr;

    if ((fpr = fopen("assignment.txt","w")) == NULL){
        printf("File can't be created!");
        fclose(fpr);
        exit(1);
    } else{
        int count = 1;
        for (int i = 0; i < 100; ++i) {
            fprintf(fpr,"%d\n",count);
            count++;
        }
        fclose(fpr);
    }

    if ((fpr = fopen("assignment.txt","r")) == NULL){
        printf("File not found!");
        fclose(fpr);
        exit(1);
    } else{
        int arr[100] = {0};
        int line = 1;
        while (!feof(fpr) && line<=100){
            fscanf(fpr, "%d",&arr[line-1]);
            printf("%d ",arr[line-1]);
            line++;
        }
        fclose(fpr);
    }
    return 0;
}

// Character a-z A-z
//int main(){
//    FILE * fpr;
//
//    if ((fpr = fopen("assignment.txt","w")) == NULL){
//        printf("File can't be created!");
//        fclose(fpr);
//        exit(1);
//    } else{
//        for (int upper = 65; upper <= 90; ++upper) {
//            fputc(upper, fpr);
//            fputs("\n",fpr);
//        }
//        for (int lower = 97; lower <= 122; ++lower) {
//            fputc(lower,fpr);
//            fputs("\n",fpr);
//        }
//        fclose(fpr);
//    }
//
//    if ((fpr = fopen("assignment.txt","r")) == NULL){
//        printf("File not found!");
//        fclose(fpr);
//        exit(1);
//    } else{
//        char arr[100] = {0};
//        int line = 1;
//        while (!feof(fpr)){
//            fscanf(fpr, "%c",&arr[line-1]);
//            printf("%c\t",arr[line-1]);
//            line++;
//            if (fgetc(fpr) == '\n'){
//                continue;
//            }
//        }
//        fclose(fpr);
//    }
//    return 0;
//}