#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node *rear;
}Cqueue;

void init(Cqueue *q){
    q->rear=NULL;
}

int insert(Cqueue *q, int val){ 
    struct node *curr=malloc(sizeof(struct node));
    
    if(curr==NULL)
    return 1;
    
    curr->next=NULL;
    curr->data=val;
    
    if(q->rear==NULL){
        curr->next=curr;
        q->rear=curr;
    }
    else{
        curr->next=q->rear->next;
        q->rear->next=curr;
        q->rear=curr;
    }
    return 0;
}

int delete(Cqueue *q, int *val){
    if(q->rear==NULL)
    return 1;
    struct node *ptr;
    if(q->rear->next==q->rear){
        *val=ptr->data;
        free(q->rear);
        q->rear=NULL;
    }
    else{
        ptr=q->rear->next;
        *val=ptr->data;
        q->rear->next=ptr->next;
        free(ptr);
    }
    return 0;
}
void display(Cqueue *q){
    struct node *ptr=q->rear->next;
    for(; ptr->next!=q->rear->next; ptr=ptr->next){
        printf("%d ", ptr->data);
    }
    printf("%d \n", ptr->data);

}
int main(){
    Cqueue q1;
    init(&q1);
    int k=insert(&q1, 20);
    k=insert(&q1, 21);
    k=insert(&q1, 22);
    k=insert(&q1, 24);
    k=insert(&q1, 25);
    display(&q1);
    int val;
    k=delete(&q1, &val);
    display(&q1);
    printf("Deleted value: %d\n", val);
}