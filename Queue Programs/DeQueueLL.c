#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node *front;
    struct node *rear;
}dequeue;

void init(dequeue *q){
    q->front=NULL;
    q->rear=NULL;
}

int insert(dequeue *q, int data, int side){
    struct node *curr=malloc(sizeof(struct node));
    curr->data=data;
    curr->next=NULL;
    if(curr==NULL){
        printf("No memory, exiting..!");
        return 1;
    }
    if(q->rear==NULL && q->front==NULL){
        q->front=q->rear=curr;
    }
    else if(side==0){
        curr->next=q->front;
        q->front=curr;
    }
    else{
        q->rear->next=curr;
        q->rear=curr;
    }
    return 0;
}

int delete(dequeue *q, int *val, int side){
    if(q->rear==NULL){
        printf("Deletion not possible! \n");
        return 1;
    }
    if(q->front==q->rear){
        *val=q->front->data;
        q->front=q->rear=NULL;
    }
    else if(side==0){
        *val=q->front->data;
        q->front=q->front->next;
    }
    else{
        *val=q->rear->data;
        
        struct node *ptr=q->front;
        while(ptr->next->next!=q->rear)
        ptr=ptr->next;
        
        q->rear=ptr;
        ptr->next=NULL;
        
    }
}

void display(dequeue *q){
    for(struct node *ptr=q->front; ptr!=NULL; ptr=ptr->next){
        printf("%d ", ptr->data);
    }
    printf("\n");
}

int main(){
    dequeue q;
    init(&q);
    int k, v;
    k=insert(&q, 4, 0);
    k=insert(&q, 5, 1);
    k=insert(&q, 6, 1);
    k=insert(&q, 3, 0);

    display(&q);

    k=delete(&q, &v, 0);
    display(&q);
    printf("Deleted value: %d\n", v);
}