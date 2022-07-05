#include<stdio.h>
#define max 100

typedef struct{
    int data[max];
    int front, rear;
}queue;

void init(queue *q){
    q->front=q->rear=-1;
}

void display(queue *q){
    for(int i=q->front; i<=q->rear; i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int insert(queue *q, int val){
    if(q->rear==max-1)
    {
        printf("Overflow!\n");
        return 1;
    }
    else if(q->rear==-1){
        q->front=q->rear=0;
        q->data[q->front]=val;
    }
    else{
        q->data[++q->rear]=val;
    }
    return 0;
}

int delete(queue *q, int *val){

    if(q->rear==-1 && q->front==-1){
        printf("Deletion not possible\n");
        return 1;
    }
    else if(q->rear==q->front){
        *val=q->data[q->front];
        q->rear=q->front=-1;
        return 0;
    }
    else{
        *val=q->data[q->front];
        q->front++;
        return 0;
    }
}

int delSpaceSave(queue *q, int *val){
     if(q->rear==-1 && q->front==-1){
        printf("Deletion not possible\n");
        return 1;
    }
    else if(q->rear==q->front){
        *val=q->data[q->front];
        q->rear=q->front=-1;
        return 0;
    }
    else{
        *val=q->data[q->front];
        for(int i=q->front+1; i<=q->rear; i++){   //shifting the elements by one place
            q->data[i-1]=q->data[i];              //to save space      
        }
        q->rear--;
    }
}

int main(){
    queue q1;
    init(&q1);

    int k=insert(&q1, 17);
    k=insert(&q1, 18);
    k=insert(&q1, 19);
    k=insert(&q1, 20);
    display(&q1);

    int v;
    k=delete(&q1, &v);
    display(&q1);
    printf("DELETED ELEMENT: %d\n", v);

    k=delSpaceSave(&q1, &v);
    display(&q1);
    printf("DELETED ELEMENT: %d\n", v);

}