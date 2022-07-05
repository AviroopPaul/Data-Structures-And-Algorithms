#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prv;
};
void display(struct node *h){
    for(;h!=NULL; h=h->next){
        printf("%d ", h->data);
    }
}
int main(){
    int n;
    struct node *curr, *head=NULL, *tail=NULL;
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        curr=malloc(n*sizeof(struct node));
        curr->next=NULL;
        curr->prv=NULL;
        curr->data=rand()%100+1;
        if(head==NULL){
            head=curr;
            tail=curr;
        }        
        else{
            curr->prv=tail;
            tail->next=curr;
            tail=curr;
        }
    }
    display(head);
}
