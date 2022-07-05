// Two types of Dequeue are there:
// 1. Input restricted 
// 2. Output Restricted 

#include<stdio.h>
#define max 100

typedef struct{
    int data[max];
    int front;
    int rear;
}dequeue;

void init(dequeue *dq){
    dq->front=dq->rear=-1;
}

int insert(dequeue *q, int val, int side){
    if(q->rear==-1){
            q->front=q->rear=0;
            q->data[q->front]=val;
        }
    else if(side==0){           //insertion at the beginning 
        if(q->front==0){
            printf("Not possible!\n");
            return 1;
        }
            q->front--;
            q->data[q->front]=val;
    }
    else{                   //insertion at the end
       if(q->rear==max-1)
       return 1;       
        q->rear++;
        q->data[q->rear]=val;
    }
    return 0;
}
int insertSpaceSave(dequeue *q, int val, int side){
    if(q->front==0 && q->rear==max-1){
        return 1;
    }
    if(q->rear==-1){
        q->front=q->rear=0;
        q->data[q->front]=val;
    }
    else if(side==0){                //insertion at the beginning
        if(q->front==0){                    
            for(int i=q->rear; i>=q->front; i--)  //shifting elements 1 position forward
            q->data[i+1]=q->data[i];
            
            q->data[q->front]=val;
            q->rear++;
        }
        else{                       
            q->front--;
            q->data[q->front]=val;
        }
    }
    else{                                        //insertion at the end
        if(q->rear==max-1){                         
            for(int i=q->front; i<=q->rear; i++){     //shifting elements 1 position backward
                q->data[i-1]=q->data[i];
            }
            q->data[q->rear]=val;
            q->front--;
        }
        else{
            q->rear++;
            q->data[q->rear]=val;
        }
    }
    return 0;
}

int delete(dequeue *q, int *v, int side){
    if(q->rear==-1)
    return 1;
    if(q->front==q->rear){
        *v=q->data[q->front];
        q->front=q->rear-1;
    }
    else if(side==0){
        *v=q->data[q->front];
        q->front++;
    }
    else{
        *v=q->data[q->rear];
        q->rear--;
    }
}

void display(dequeue *q){
    for(int i=q->front; i<=q->rear; i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main(){
    dequeue d1;
    int k, v;
    init(&d1);
    k=insert(&d1, 10, 0);
    k=insert(&d1, 9, 0);
    k=insert(&d1, 11, 1);
    k=insert(&d1, 8, 0);
    k=insert(&d1, 12, 1);

    printf("Inserted using normal insert function: \n");    
    display(&d1);

    k=insertSpaceSave(&d1, 13, 1);
    k=insertSpaceSave(&d1, 9, 0);
    k=insertSpaceSave(&d1, 8, 0);
    k=insertSpaceSave(&d1, 7, 0);

    printf("Inserted using space sace insert function: \n");    
    display(&d1);

    printf("\n");
    delete(&d1, &v, 0);
    display(&d1);
    printf("Deleted value: %d\n", v);
    delete(&d1, &v, 1);
    display(&d1);
    printf("Deleted value: %d\n", v);
}