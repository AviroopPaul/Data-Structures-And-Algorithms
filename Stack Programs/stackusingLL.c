#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
};

typedef struct{
    struct node *top;
}stack;

int push(stack *, int);
int pop(stack *, struct node **);
void init(stack *); 

void init(stack *s){
    s->top=NULL;
}

int push(stack *s, int val){
    struct node *curr=malloc(sizeof(struct node));
    if(curr==NULL)
    {
        printf("Overflow");
        return 1;
    }
    curr->val=val;
    curr->next=s->top;
    s->top=curr;
    return 0;
}

int pop(stack *s, struct node **ptr){
    if(s->top==NULL){
        printf("Underflow!\n");
        return 1;
    }
    *ptr=s->top;
    s->top=s->top->next;
    return 0;
}

void display(struct node *s, int k){
    if(k==0){
        struct node *ptr=s;
        while(ptr!=NULL){
            printf("%d\n", ptr->val);
            ptr=ptr->next;
        }
    }
}

int main(){
    stack s1;
    init(&s1);
    int k=push(&s1, 10);
    k=push(&s1, 11);
    k=push(&s1, 12);
    k=push(&s1, 15);
    k=push(&s1, 14);
    k=push(&s1, 9);
    display(s1.top, k);

    struct node *ptr;
    k=pop(&s1, &ptr);
    printf("After popping: \n");
    display(s1.top, k);
    if(k==0)
    printf("Popped element is: %d.\n", ptr->val);
    k=pop(&s1, &ptr);
    printf("After popping: \n");
    display(s1.top, k);
    if(k==0)
    printf("Popped element is: %d.\n", ptr->val);
}