#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int *a, int i, int j){
    int l, u, pivot;
    l=i;
    u=j;
    pivot=a[i];
    while(l<u){
        while(a[l]<=pivot && l<j){
            l++;
        }
        while(a[u]>pivot){
            u--;
        }
        if(l<u){
            swap(&a[l], &a[u]);
        }
    }
    swap(&a[i], &a[u]);
    return u;
}



void quickSort(int *a, int l, int u){
    if(l<u){
        int pos=partition(a,l,u);
        quickSort(a, l, pos-1);
        quickSort(a, pos+1, u);
    }
}

int main(){
    int arr[]={10,8,9,7,15,5,1};
    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    quickSort(arr,0,sizeof(arr)/sizeof(int)-1);
    printf("Sorted:\n");
    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
}