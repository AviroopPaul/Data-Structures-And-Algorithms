#include<stdio.h>
int cnoe=0;
#define max 10

void insert(int *a, int val, int pos){
    if(cnoe==max)
    printf("\nArray is full!\n");
    else{
        if(pos>=cnoe){
            a[cnoe]=val;
            cnoe++;
        }
        else
        {
            for(int i=cnoe-1; i>=pos; i--){

                a[i+1]=a[i];
            }
            a[pos]=val;
            cnoe++;
        }
    }
}

void deletepos(int *a, int pos){
    if(cnoe==0 || pos>=cnoe)
    printf("Impossible to delete! Either array is empty or position is out of bounds.\n");
    else{
        for(int i=pos+1; i<cnoe; i++)
        {
            a[i-1]=a[i];
        }
        cnoe--;
    }
}

void deleteval(int *a, int val){
    if(cnoe==0)
    printf("\nImpossible to delete!\n");
    else{
        int i;
        for(i=0; i<cnoe; i++)
        {
            if(a[i]==val){
                break;
            }
        }
        if(i==cnoe)
        printf("Value not present in the list!\n");
        else
        {
            for(int j=i+1; j<cnoe; j++){
                a[j-1]=a[j];
            }
            cnoe--;
        }
        
    }
}




void display( int *a){
    for(int i=0; i<cnoe; i++)
    printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int arr[max];
    
    insert(arr,10,3);
    insert(arr,11,2);
    insert(arr,9,1);
    insert(arr,8,0);
    display(arr);

    deletepos(arr, 3);
    display(arr);
    deleteval(arr, 8);
    display(arr);
    
    deleteval(arr, 20);
    //display(arr);
    deletepos(arr, 5);
    //display(arr);
}

