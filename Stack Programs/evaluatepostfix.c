#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100

typedef struct{
    int data[max];
    int top;
}stack;
void init(stack *s){
    s->top=-1;
}
int push(stack *s, int val){
    if(s->top==max)
    printf("Overflow!\n");
    else{
        s->top++;
        s->data[s->top]=val;
    }
}

int pop(stack *s){
    if(s->top==-1)
    printf("Underflow!\n");
    else{
        int val=s->data[s->top];
        s->top--;
        return val;
    }
}

int isOperand(int outf){
    if(outf>=0 && outf<=9)
    return 1;
    else 
    return 0;
}

int evaluatePost(char *outf){
    stack s2;
    init(&s2);
    for(int i=0; i<strlen(outf); i++){
        if(isdigit(outf[i])){
            push(&s2, outf[i]-'0'); // the -'0' is very important as it verifies if it is a digit
        }
        else{
            int v1=pop(&s2); 
            int v2=pop(&s2);
            switch(outf[i]){
                case '+': push(&s2, v2+v1);
                break;
                case '-': push(&s2, v2-v1);
                break;
                case '*': push(&s2, v2*v1);
                break;
                case '/': push(&s2, v2/v1);
                break;
            }
            
        }
    }
    int result=pop(&s2);
    return result;
}

int main(){
    char outf[100]="12+63/2*+5-";
    printf("Postfix expression: %s", outf);
    int res=evaluatePost(outf);
    printf("\nAfter evaluating: %d", res);
}