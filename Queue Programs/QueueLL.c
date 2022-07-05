#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct{
    struct node *front;
    struct node *rear;
}queue;

void init(queue *q){
    q->front=q->rear=NULL;
}

int insert(queue *q, int val){
    struct node *curr=malloc(sizeof(struct node));
    if(curr==NULL)
    {
        printf("Insertion not possible\n");
        return 1;
    }
    curr->data=val;
    curr->next=NULL;
    if(q->front==NULL || q->rear==NULL){  //only one node present
        q->front=q->rear=curr;
    }
    else{
        q->rear->next=curr;
        q->rear=curr;
    }
    return 0;
}

int delete(queue *q, int *val){
    if(q->front==NULL){
        printf("Deletion is not possible, Queue empty.\n");
        return 1;
    }
    if(q->rear==q->front){
        *val=q->front->data;
        q->rear=q->front=NULL;
    }
    else{
        *val=q->front->data;
        struct node *ptr=q->front;
        q->front=q->front->next;
        free(ptr);
    }
    return 0;
}

void display(queue *q){
    for(struct node *ptr=q->front; ptr!=NULL; ptr=ptr->next){
        printf("%d ", ptr->data);
    }
    printf("\n");
}

int main(){
    queue q1;
    int val,k;
    k=delete(&q1, &val);
    
    k=insert(&q1, 10);
    k=insert(&q1, 11);
    k=insert(&q1, 12);
    k=insert(&q1, 13);
    k=insert(&q1, 14);
    display(&q1);

    k=delete(&q1, &val);
    display(&q1);
    printf("Deleted Element: %d\n", val);
}