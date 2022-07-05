#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selectionSort(int *a, int size){
    for(int i=0; i<size-1; i++){   //selected position
        int min=i+1;
        for(int j=i+2;j<size;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(a[min]<a[i])
        swap(&a[min],&a[i]);
    }
}

int main(){
    int arr[]={10,9,7,12,8,19,1};
    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    selectionSort(arr,sizeof(arr)/sizeof(int));
    printf("Sorted\n");
    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
}