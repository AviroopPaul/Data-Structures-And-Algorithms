#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node *rear;
    struct node *front;
}CircDequeue;

void init(CircDequeue *q){
    q->rear=NULL;
    q->front=NULL;
}

int insert(CircDequeue *q, int data, int side){
    struct node *curr=malloc(sizeof(struct node));
    if(curr==NULL)
    return 1;

    curr->data=data;
    curr->next=NULL;

    if(q->rear==NULL && q->front==NULL){
        q->front=q->rear=curr;
    }
    else if(side==0){
        q->rear->next=curr;
        curr->next=q->front;
        q->front=curr;
    }
    else{
        q->rear->next=curr;
        curr->next=q->front;
        q->rear=curr;
    }
}

int delete(CircDequeue *q, int *val, int side){
    if(q->front==NULL && q->rear==NULL){
        printf("Queue is empty!\n");
        return 1;
    }
    if(q->front==q->rear){
        *val=q->front->data;
        q->front=q->rear=NULL;
    }
    else if(side==0){
        *val=q->front->data;
        struct node *ptr=q->front;
        q->front=q->front->next;
        q->rear->next=q->front;
        free(ptr);
    }
    else{
        *val==q->rear->data;
        struct node *ptr;
        while(ptr->next!=q->rear)
        ptr=ptr->next;

        ptr->next=NULL;
        free(q->rear);
        q->rear=ptr;
    }
}

void display(CircDequeue *q){
    struct node *ptr=q->front;
    for(; ptr->next!=q->front; ptr=ptr->next){
        printf("%d ", ptr->data);
    }
    printf("%d \n", ptr->data);
}
int main(){
    CircDequeue q;
    int k, v;
    init(&q);
    k=insert(&q, 10, 0);
    k=insert(&q, 11, 1);
    k=insert(&q, 12, 1);
    k=insert(&q, 9, 0);
    display(&q);

    k=delete(&q, &v, 0);
    display(&q);
    printf("Deleted element: %d\n", v);
    
}