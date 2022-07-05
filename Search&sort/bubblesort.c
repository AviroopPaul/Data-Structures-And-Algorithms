#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleSort(int *a, int size){
    for(int i=0; i<size-1; i++){
        int flag=0;
        for(int j=0; j<size-1-i; j++){
            if(a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
}

int main(){
    int arr[]={10,9,7,12,8,19,1};
    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr,sizeof(arr)/sizeof(int));
    printf("Sorted\n");
    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
}