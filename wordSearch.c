// This program helps you to search the number of words in the file.
// But this program can search only the words with no white space.

#include "stdio.h"
#include "stdlib.h"

int inputs(char str[]);

int main(){
    FILE *fpr;
    char word[100];
    printf("Enter the word that you want to search : ");
    inputs(word);
    int numWord = 0;

    if ((fpr = fopen("words.txt","r")) == NULL){
        printf("File can't be opened!!");
        fclose(fpr);
        exit(1);
    }

    while (!feof(fpr)){
        char strFile[100] = "";
        char toCat;
        int i = 0;
        int j = 0;
        int flag = 0;

        while (((toCat = fgetc(fpr)) != ' ') && (toCat != '\377') && (toCat != '\n')){
            strFile[i] = toCat;
            i++;
        }

        while (j<i){
            if (strFile[j] == word[j]){
                flag = 1;
                j++;
                continue;
            } else{
                flag = 0;
                break;
            }
        }
        numWord += flag==1 ? 1 : 0;
    }
    fclose(fpr);
    printf("\nThe number of words %d",numWord);
    return 0;
}

int inputs(char str[]){
    int ch, i = 0;
    while ((ch=getchar()) != '\n'){
        str[i] = ch;
        i++;
    }
    str[i] = '\0';
    return i;
}
