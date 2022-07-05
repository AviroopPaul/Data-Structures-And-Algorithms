#include<stdio.h>
#define MAX 100

typedef struct{
    int data[MAX];
    int top;
}stack;

int push(stack *, char);
int pop(stack *, char *);
void init(stack *);

void init(stack *s1){
    s1->top=-1;
}

int push(stack *s1, char val){
    if(s1->top==MAX-1){
        printf("Push operation not possible, OVERFLOW!\n");
        return 1;
    }
    s1->top++;
    s1->data[s1->top]=val;
    return 0;
}

int pop(stack *s1, char *val){
    if(s1->top==-1){
        printf("Pop operation not possible/completed. \n");
        return 1;
    }
    *val=s1->data[s1->top];
    s1->top--;
    return 0;
}

int isEmpty(stack *s1){
    if(s1->top==-1)
    return 1;
    else
    return 0;
}

int isOperand(char ele){
    if(ele>='A' && ele<='Z' || ele>='a' && ele<='z' )
    return 1;
    else
    return 0;
}

int getv(char ele){
    int k=0;
    switch(ele){
        case '+':
        case '-': k=1;
                break;
        case '*':
        case '/': k=2;
                break;
    }
    return k;
}

int isLH(char t, char inf){
    if(getv(t)<getv(inf))
    return 1;
    else
    return 0;
}



void infixtopost(stack *s1, char *inf, char *outf){
    int i=0, j=0;
    char t;
    while(inf[i]!='\0'){
        if(isOperand(inf[i]))
        outf[j++]=inf[i];
        else if(inf[i]=='(')
        {
            push(s1, inf[i]);
        }
        else if(inf[i]==')'){
            while(1){
                pop(s1, &t);
                if(t=='(')
                break;
                outf[j++]=t;
            }
        }
        //IF THE ELEMENT IS AN OPERATOR
        else{
            if(isEmpty(s1))
            push(s1, inf[i]);
            else{
                pop(s1, &t);
                if(t=='('){
                    push(s1, '(');
                    push(s1, inf[i]);
                }
                else{
                    if(isLH(t, inf[i])){
                        push(s1, t);
                        push(s1, inf[i]);
                    }
                    else{
                        outf[j++]=t;
                        i--;
                    }
                }
            }
        }
        i++;
    }
    int k;
    while((k=pop(s1, &t))==0) //popping rest of the remaining elements of the stack
    outf[j++]=t;
    outf[j]='\0';
}

// int evaluatePost(char *outf){
//     stack s2;
//     for(int i=0; i<strlen(outf); i++){
//         if(isOperand(outf[i])){
//             push(&s2, outf[i]);
//         }
//         else{
//             int v1; int v2;
//             pop(&s2, &v1);
//             pop(&s2, &v2);
//             switch(outf[i]){
//                 case '+': push(&s2, v2+v1);
//                 case '-': push(&s2, v2-v1);
//                 case '*': push(&s2, v2*v1);
//                 case '/': push(&s2, v2/v1);
//             }
            
//         }
//         int result;
//         pop(&s2, &result);
//         return result;
//     }
// }

int main(){
    stack s1;
    init(&s1);
    char inf[MAX]="A+B-(D*K+P)/R";
    printf("INFIX EXPRESSION: %s\n", inf);
    char outf[100];
    infixtopost(&s1, inf, outf);
    printf("OUTPUT(POSTFIX EXPRESSION): %s", outf);
}