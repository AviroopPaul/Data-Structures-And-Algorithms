#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *a,int size){
    int j,i,temp;
    for(i=1; i<size; i++){
        temp=a[i];
        for(j=i-1; j>=0; j--){
            if(a[j]>temp){
                a[j+1]=a[j];
            }
            else
            break;
        }
        a[j+1]=temp;
    }

}

int main(){
    int arr[]={10,8,9,7,15,5,1};
    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertionSort(arr,sizeof(arr)/sizeof(int));
    printf("Sorted\n");
    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }

}