#include<stdio.h>
#include<stdlib.h>
#define max 50

typedef struct{
    int data[max];
    int front;
    int rear;
}Cqueue;

void init(Cqueue *q){
    q->front=q->rear=-1;
}

int delete(Cqueue *q, int *val){
    if(q->front==-1)
    return 1;
    if(q->front==q->rear){
        *val=q->data[q->front];
        q->front=q->rear=-1;
    }
    else{
        *val=q->data[q->front];
        q->front=(q->front+1)%max;
    }
    return 0;
}

int insert(Cqueue *q, int val){
    if(q->front==(q->rear+1)%max)
    return 1;
    if(q->rear==-1){
        q->front=q->rear=0;
        q->data[q->front]=val;
    }
    else
    {
        q->rear=(q->rear+1)%max;
        q->data[q->rear]=val;
    }
    return 0;
}

void display(Cqueue *q){
    int i=q->front;
    do{
        printf("%d ", q->data[i]);
        i=(i+1)%max;
    }while(i!=q->rear);
    printf("%d ", q->data[i]);
    printf("\n");
}

int main(){
    Cqueue q1;
    init(&q1);
    int k= insert(&q1, 20);
    k= insert(&q1, 21);
    k= insert(&q1, 22);
    k= insert(&q1, 23);
    display(&q1);
    int val;
    k=delete(&q1, &val);
    display(&q1);
    printf("Deleted value: %d\n", val);
}