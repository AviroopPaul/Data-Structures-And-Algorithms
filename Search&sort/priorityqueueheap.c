#include<stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void pqueueheap(int *a, int size){
    int n=0;
    for(int k=0; k<size; k++){
        int i=n;
        int temp=a[k];
        while(i>0){
            int j=((i+1)/2)-1;
            if(a[j]>temp){
                a[i]=a[j];
                i=j;
            }
            else
            break;
        }
        a[i]=temp;
        n++;
    }
}

int main(){
    int a[10]={5,3,7,1,10,21,6,4,2,8};
    int n=sizeof(a)/sizeof(int);
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }printf("\n");

    pqueueheap(a, n);

    printf("After making min-heap: \n");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }printf("\n");
    
}