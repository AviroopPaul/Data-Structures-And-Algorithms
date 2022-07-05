#include<stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int *a, int i, int n){
    int lc=2*i+1, rc=2*i+2;
    int max=i;
    if(lc<n && a[max]<a[lc])
    max=lc;
    if(rc<n && a[max]<a[rc])
    max=rc;
    if(i!=max){
        swap(&a[i], &a[max]);
        heapify(a, max, n);
    }
}

int main(){
    int a[10]={5,3,7,1,10,21,6,4,2,8};
    int n=sizeof(a)/sizeof(int);
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }printf("\n");

    for(int i=n/2-1; i>=0; i--){
        heapify(a, i, n);
    }

    while(n>1){
        swap(&a[0], &a[n-1]);
        heapify(a, 0, n-1);
        n--;
    }
    printf("After sorting:\n");
    for(int i=0; i<sizeof(a)/sizeof(int); i++){
        printf("%d ", a[i]);
    }
}