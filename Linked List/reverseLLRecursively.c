#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void reverseRecursive(struct node **h, struct node *ptr){
    if(ptr==NULL || ptr->next==NULL){
        return;
    }
    else{
        struct node *ptr1=ptr->next;
        ptr->next=ptr1->next;
        ptr1->next=*h;
        *h=ptr1;
        reverseRecursive(h, ptr);
    }
}

void display(struct node *h){
    for(struct node *ptr=h; ptr!=NULL; ptr=ptr->next)
    printf("%d -> ", ptr->data);
    printf("NULL\n");
}

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
        printf("%d -> ", curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
    reverseRecursive(&head,head);
    printf("After reversing: \n");
    display(head);
}