#include<stdio.h>

#define MAX 6

typedef struct{
    int data[MAX];
    int top;
}stack;

int push(stack *, int);
int pop(stack *, int *);
void init(stack *);

void init(stack *s){
    s->top=-1;
}

int push(stack *s, int val){
    if(s->top==MAX-1){
        printf("Overflow!\n");
        return 1;
    }
    s->top++;
    s->data[s->top]=val;
    return 0;
}

int pop(stack *s, int *val){
    if((s->top==-1)){
        printf("Underflow!\n");
        return 1;
    }
    *val=s->data[s->top];
    s->top--;
    return 0;
}

void display(stack s, int top){
    for(int i=top; i>=0; i--){
        printf("%d\n", s.data[i]);
    }
}

int main(){
    int k;
    stack s1;
    init(&s1);
    k=push(&s1, 10);
    k=push(&s1, 12);
    k=push(&s1, 13);
    k=push(&s1, 9);
    k=push(&s1, 11);

    display(s1, s1.top);

    int v;
    k=pop(&s1, &v);
    printf("After popping: \n");
    display(s1, s1.top);
    if(k==0){
        printf("Popped value is: %d", v);
    }

    
}