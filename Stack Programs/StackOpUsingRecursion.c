#include<stdio.h>

#define MAX 100

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

int isEmpty(stack *s){
    if(s->top==-1)
    return 1;
    else
    return 0;
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

void display(stack *s){    //DISPLAY USING RECURSION
    if(!isEmpty(s)){
        int v;
        pop(s, &v);
        printf("%d ", v);
        display(s);
        push(s,v);
    }
}

void inSort(stack *s, int val){
    if(isEmpty(s))
    push(s,val);
    else{
        int popele;
        pop(s, &popele);
        if(popele>val){
            inSort(s, val);
            push(s, popele);    //pushing the popped element
        }
        else{
            push(s,popele);     //pushing the smaller element first
            push(s, val);       //pushing the bigger element next
        }
    }
}

void sort(stack *s){
    if(!isEmpty(s)){
        int val;
        pop(s, &val);       //popping the first element of the stakck
        sort(s);            //giving the rest of the job to sort
        inSort(s, val);     //inserting the element using the inSort() function
}
}

int main(){
    int k;
    stack s1;
    init(&s1);
    k=push(&s1, 10);
    k=push(&s1, 8);
    k=push(&s1, 7);
    k=push(&s1, 12);
    k=push(&s1, 18);
    printf("Before sorting \n");
    display(&s1);
    printf("\nAfter sorting \n");
    sort(&s1);
    display(&s1);
    printf("\n");
    
    inSort(&s1, 14);
    inSort(&s1, 16);
    inSort(&s1, 9);
    
    display(&s1);

    
}