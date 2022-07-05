#include<stdio.h>
#define max 100

struct prival{
    int val;
    int pri;
};

typedef struct{
    struct prival data[max];
    int front, rear;
}pqueue;

void init(pqueue *q){
    q->front=-1;
    q->rear=-1;
}

int insert(pqueue *q, int val, int pri){
    if(q->rear==max-1){
        printf("Queue is full\n");
        return 1;
    }
    if(q->rear==-1){
        q->front=q->rear=0;
        q->data[q->front].val=val;
        q->data[q->front].pri=pri;
    }
    else{
        q->rear++;
        q->data[q->rear].val=val;
        q->data[q->rear].pri=pri;
    }
    return 0;
}

int delete(pqueue *q, int *v){               //delete priority wise while deletion
    if(q->rear==-1){
        printf("Queue is empty!\n");
        return 1;
    }
    if(q->rear==q->front){
        *v=q->data[q->rear].val;
        q->front=q->rear=-1;
        return 0;
    }
    printf("%d\n", q->front);
    int i;
    int min=q->front;
    for(i=q->front+1; i<=q->rear; i++){
        if(q->data[i].pri < q->data[min].pri)
        min=i;
    }
    *v=q->data[min].val;
    q->data[min]=q->data[q->rear];
    q->rear--;
    return 0;
}

void display(pqueue *q){
    int j=1;
    for(int i=q->front; i<=q->rear; i++){
        printf("Priority %d -> %d \n", j,q->data[i].val);
        j++;
    }
    printf("\n");
}

int main(){
    pqueue q1;
    init(&q1);
    int k, v;
    k=insert(&q1, 11, 2);
    k=insert(&q1, 10, 5);
    k=insert(&q1, 12, 4);
    k=insert(&q1, 13, 1);
    k=insert(&q1, 14, 3);


    display(&q1);

    k=delete(&q1, &v);
    printf("Element deleted: %d\n", v);
    display(&q1);

    k=delete(&q1, &v);
    printf("Element deleted: %d\n", v);
    display(&q1);

    k=delete(&q1, &v);
    printf("Element deleted: %d\n", v);
    display(&q1);
}