#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head=NULL, *curr,*ptr;
    int n;
    printf("Enter number of nodes you want: \n");
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        curr=malloc(n*sizeof(struct node));
        curr->next=NULL;
        curr->data=rand()%100;
        if(head==NULL){
            head=curr;
            ptr=curr;
        }
        else{
            ptr->next=curr;
            ptr=curr;
        }

    }
    
    curr=head;
    while(curr!=NULL){
        printf("%d ", curr->data);
        curr=curr->next;
    }

}