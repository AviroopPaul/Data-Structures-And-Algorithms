#include<stdio.h>
#include<stdlib.h>


int* merge(int *a, int l, int m, int u){
    int i,j,k=0;
    int *op=malloc(sizeof(int)*(u-l+1));
    i=l;
    j=m+1;

    while(i<=m && j<=u){
        if(a[i]<a[j]){
            op[k++]=a[i++];
        }
        else{
            op[k++]=a[j++];
        }
    }
    
    while(i<=m){    //if some elements remain in i part 
        op[k++]=a[i++];
    }

    while(j<=u){    //if some elements remain in j part
        op[k++]=a[j++];
    }

    for(int x=0; x<k;x++){  //transferring elements of output array to original array
        a[l+x]=op[x];
    }
}

void mergeSort(int *a, int l, int u){
    if(l<u){
        int m=(l+u)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,u);
        merge(a,l,m,u);
    }
    
}

int main(){
    int arr[]={10,8,9,7,15,5,1};
    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr,0,sizeof(arr)/sizeof(int)-1);
    
    printf("Sorted:\n");
    for(int i=0; i<sizeof(arr)/sizeof(int); i++){
        printf("%d ", arr[i]);
    }
}