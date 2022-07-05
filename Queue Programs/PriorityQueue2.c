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

int insert(pqueue *q, int val, int pri){    //sorting priority wise while inserting
    if(q->rear==max-1){
        return 1;
    }
    if(q->rear==-1){
        q->front=q->rear=0;
        q->data[q->rear].val=val;
        q->data[q->rear].pri=pri;
        return 0;
    }
    int i;
    for(i=q->front; i<=q->rear; i++){
        if(q->data[i].pri>pri)
        break;
    }
    for(int j=q->rear; j>=i; j--){
        q->data[j+1]=q->data[j];
    }
    q->data[i].val=val;
    q->data[i].pri=pri;
    q->rear++;
    return 0;
}


int delete(pqueue *q, int *v){
    if(q->rear==-1){
        return 1;
    }
    if(q->rear==q->front){
        *v=q->data[q->front].val;
        q->rear=q->front=-1;
    }
    else{
        *v=q->data[q->front].val;
        q->front++;
    }
    return 0;
}

void display(pqueue *q){
    for(int i=q->front; i<=q->rear; i++){
        printf("%d ", q->data[i].val);
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