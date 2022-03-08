#include  "isort.h"
#include <stdio.h>

void shift_element(int* arr, int i){
    int temp;
    int* end=arr+i;
    while(end>arr){
        temp=*(end-1);
        *end=temp;
        end--;
    }

}

void insertion_sort(int* arr , int len){
    int temp,j;
    for (int i = 1; i < len; ++i) {
        temp = *(arr + i);
        j = 0;
        while (j<i&&temp>*(arr+j)) {
            j++;
        }
        if (i - j != 0){
            shift_element(arr +j, i - j);
        *(arr + j) = temp;
    }
    }
}

int main() {
    int arr[50];
    for(int i=0;i<50;i++){
        printf("please enter number No.%d: ",i+1);
        scanf("%d ",(arr+i));
    }
    size_t len=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,len);
    printf("\n");
    for(int k=0;k<49;k++){
        printf("%d," ,*(arr+k));
    }
    printf("%d",*(arr+49));
    return 0;
}


