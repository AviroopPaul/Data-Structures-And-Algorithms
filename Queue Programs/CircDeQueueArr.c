#include<stdio.h>
#define max 4

typedef struct{
    int data[max];
    int rear;
    int front;
}Circdequeue;

void init(Circdequeue *q){
    q->front=q->rear=-1;
}

int insert(Circdequeue *q, int data, int side){
    if(q->front==(q->rear+1)%max){
        printf("Queue is full!\n");
        return 1;
    }
    
    if(q->rear==-1){
        q->front=q->rear=0;
        q->data[q->front]=data;
    }
    
    else if(side==0){
        q->front=(q->front+max-1)%max;
        q->data[q->front]=data;
    }
    else{
        q->rear=(q->rear+1)%max;
        q->data[q->rear]=data;
    }
    return 0;
}

int delete(Circdequeue *q, int *val, int side){
    if(q->rear==-1 && q->front==-1){
        printf("Deletion is not possible, queue empty!\n");
        return 1;
    }
    if(q->front==q->rear){
        *val=q->data[q->front];
        q->front=q->rear=-1;
    }
    else if(side==0){
        *val=q->data[q->front];
        q->front=(q->front+1)%max;
    }
    else{
        *val=q->data[q->rear];
        q->rear=(q->rear+max-1)%max;
    }
    return 0;
}

void display(Circdequeue *q){
    int i=q->front;
    do{
        printf("%d ", q->data[i]);
        i=(i+1)%max;
    }while(i!=q->rear);
    printf("%d ", q->data[i]);
    printf("\n");
}

int main(){
    Circdequeue q;
    init(&q);
    int k, v;
    k=insert(&q, 10, 0);
    k=insert(&q, 11, 1);
    k=insert(&q, 12, 1);
    k=insert(&q, 9, 0);
    display(&q);

    k=delete(&q, &v, 0);
    display(&q);

    k=insert(&q, 13, 1);
    display(&q);
      
}