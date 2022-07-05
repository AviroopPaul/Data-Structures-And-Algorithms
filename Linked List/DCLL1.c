#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;

void display(struct node *h){
    struct node *ptr=h;
    do{   
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }while(ptr!=h);
}

int main(){
    //struct node *head=NULL;
    int n;
    scanf("%d", &n);
    for( int i=0; i<n;i++){
        struct node *curr;
        curr=malloc(sizeof(struct node));
        curr->data=rand()%100;
        curr->next=NULL;
        curr->prev=NULL;
        if(head==NULL)
        head=curr->prev=curr->next=curr;
        else{
            curr->prev=head->prev;
            curr->next=head;
            head->prev->next=curr;
            head->prev=curr;
        }
    }
    display(head);
}