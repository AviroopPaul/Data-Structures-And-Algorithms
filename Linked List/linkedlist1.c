#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(struct node **h, int n){
        
        struct node *ptr, *curr;
        curr= malloc(n*sizeof(struct node));
        curr->next=NULL;
        curr->data=rand()%100;
        if(*h==NULL){
            *h=curr;
        }
        else{
            ptr=*h;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=curr;
        }
}


void display(struct node *h){
    for(;h!=NULL; h=h->next)
    printf("%d ", h->data);
}

void rearrange (struct node *list) 
{
    struct node *p, *q;
    int temp;
    if (!list || !list -> next) 
        return;
    p = list; 
    q = list -> next;
    while (q) 
    {
        temp = p -> data;
        p -> data = q -> data;
        q -> data = temp;
        p = q -> next -> next;
        q = p ? p -> next : 0;
    }
    display(list);
}




int main(){
    int n;
    struct node *head=NULL;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        insert(&head, n);
    }
    display(head);
    printf("\n");
    rearrange(head);
}
    
