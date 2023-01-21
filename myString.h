//
// Created by galax on 1/17/2023.
//

#ifndef C_MYSTRING_H
#define C_MYSTRING_H
#include "stdio.h"
#include "stdlib.h"
#define true  1
#define false 0


void upper(char *str);
void lower(char *str);
int stringLen(const char *str);
int stringCmp(char *str1, char *str2);
void stringCp(char *origin, char *buff);
int StrInput(char str[]);
int regExpress(char *str, char *pattern);


void upper(char *str){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] >= 97 && str[i] <= 122) str[i] -= 32;
        i++;
    }
}

void lower(char *str){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] >= 65 && str[i] <= 90) str[i] += 32;
        i++;
    }
}

int stringLen(const char *str){
    int n=0;
    while(str[n++] != '\0');
    return n-1;
}

int stringCmp(char *str1, char *str2){
    int cnt=0;
    if(stringLen(str1) == stringLen(str2)){
        while(str1[cnt] != '\0'){
            if(str1[cnt] == str2[cnt])
                cnt++;
            else
                return 0;
        }
        return 1;
    }
    else
        return 0;
}

void stringCp(char *origin, char *buff){
    int len = stringLen(origin);
    for(int i=0; i<len; i++){
        buff[i] = origin[i];
    }
}

int strInput(char str[]){
    int ch, i = 0;
    while ((ch=getchar()) != '\n') str[i++] = ch;
    str[i] = '\0';
    return i;
}



/* "Word Checker whether each character in the string existed in the patterns or not"
 * patterns => [start char] - [end char]
 * example  => a-z a,b,c,....,x,y,z
 * example  => 0-9 0,1,2,....,8,9
 * you can put any sequences from ascii table
 * RETURN: 1 if each character existed in patterns else 0
 * */
int regExpress(char *str, char *pattern){
    char pat_char[100] = {'\0'}; int pat_idx = 0;
    int pat_length = stringLen(pattern);
    int str_length = stringLen(str);
    for(int index=1; index < pat_length;){
        if(pattern[index] == '-'){
            if(index-1 <= index+1){
                for(char ch=pattern[index-1]; ch<=pattern[index+1]; ch++){
                    pat_char[pat_idx++] = ch;
                }
            }
            else
                printf("[-] Found pattern index error!!![pattern excluded]\n");
        }
        else{
            printf("[-] Found strange patter!!![pattern excluded]\n");
        }
        index += 3;
    }
    int i=0;
    int patChar_length = stringLen(pat_char);
    while(str[i] != '\0'){
        int found = false;
        for(int j=0; j<patChar_length; j++){
            if(str[i] == pat_char[j]){
                found = true;
                break;
            }
        }
        if(!found)
            return 0;
        i++;
    }
    return 1;
}
#endif
