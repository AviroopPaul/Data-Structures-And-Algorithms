#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL;

void display(struct node *h){
    struct node *ptr;
    if(h!=NULL){
        ptr=h;
        do{
            printf("%d ", ptr->data);
            ptr=ptr->next;
        }while(ptr!=h);
    }
    else
    printf("Node is empty.\n");
}

int main(){
    struct node *curr,*ptr;
    int n;
    scanf("%d", &n);
    for( int i=0; i<n;i++){
        curr=malloc(n*sizeof(struct node));
        curr->next=NULL;
        curr->data=rand()%100;
        if(head==NULL){
            head=curr;
            curr->next=head;
            ptr=curr;
        }
        else{
            curr->next=head;
            ptr->next=curr;
            ptr=curr;
        }
    }
    display(head);
}