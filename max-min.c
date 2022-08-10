#include "stdio.h"


void remove_element(int *array, int index, int array_length);


int main(){
    int length = 0;
    FILE *maxs;
    FILE *mins;
    maxs = fopen("max.txt","w");
    mins = fopen("min.txt","w");
    printf("Enter the length of array:");
    scanf("%d", &length);

    if (length%2 == 0){
        int arr[length];
        printf("Enter the items:");

        for (int i = 0; i<length; i++){
            scanf("%d", &arr[i]);
        }

        int temp;
        for (int i = 0; i < length; i++) {
            for (int j = i+1; j < length; j++) {
                if(arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        if (maxs!=NULL && mins!=NULL){
            while (length!=0){
                int min = arr[0];
                int max = arr[length-1];
                fprintf(maxs, "%d\t", max);
                fprintf(mins, "%d\t", min);
                remove_element(arr, 0, length);
                length--;
                remove_element(arr, length-1, length);
                length--;
            }
        }
        else{
            printf("The files can't be opened!!!");
        }
    }
    else{
        printf("Please enter even numbers!!!");
    }
    fclose(maxs);
    fclose(mins);

    return 0;
}

void remove_element(int *array, int index, int array_length)
{
    int i;
    for(i = index; i < array_length - 1; i++) {
        array[i] = array[i + 1];
    }
}
