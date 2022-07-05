#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct{
    int data[max];
    int top[2];
}dstack;

void init(dstack *s){
    s->top[0]=-1;
    s->top[1]=max;
}

int push(dstack *s, int val, int type){
    if(s->top[0]==s->top[1]-1){
        printf("Overflow!\n");
        return 1;
    }
    else{
        if(type==0){
            (s->top[type])++;
            s->data[s->top[type]]=val;
        }
        else{
            s->top[type]--;
            s->data[s->top[type]]=val;
        }
        return 0;
    }
}

int pop(dstack *s, int *val, int type){
    if(type==0 && s->data[type]==-1 || type==1 && s->data[type]==max){
        printf("Underflow!\n");
        return 1;
    }
    else{
        if(type==0){
            *val=s->data[s->top[type]];
            s->top[type]--;
            
        }
        else{
            *val=s->data[s->top[type]];
            s->top[type]++;
        }
        return 0;
    }
}

void display(dstack *s, int type){
    if(type==0){
    for(int i=s->top[0]; i>=0; i--){
        printf("%d\n", s->data[i]);
    }
    }
    else{
        for(int i=s->top[1]; i<max; i++){
            printf("%d\n", s->data[i]);
        }
    }
}

int main(){
    dstack s1;
    init(&s1);
    int k, v; 
    k=push(&s1, 10, 0);
    k=push(&s1, 12, 0);
    k=push(&s1, 13, 0);
    k=push(&s1, 14, 1);
    k=push(&s1, 15, 1);
    k=push(&s1, 16, 0);
    printf("\nDisplaying 1st stack: \n");
    display(&s1, 0);
    printf("Displaying 2nd stack:\n");
    display(&s1, 1);
    k=pop(&s1, &v, 1);
    if(k==0)
    printf("Popped element of 2nd stack:%d \n", v);
    k=pop(&s1, &v, 0);
    if(k==0)
    printf("Popped element of 1st stack:%d \n", v);
    printf("\nDisplaying 1st stack: \n");
    display(&s1, 0);
    printf("Displaying 2nd stack:\n");
    display(&s1, 1);
}