#include<stdio.h>
#include<stdlib.h>
#define max 6

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct{
    struct node *data[max];
    int top;
}stack;

void init(stack *s){
    s->top=-1;
}

int push(stack *s, struct node *val){
    if(s->top==max-1){
        printf("Overflow!\n");
        return 1;
    }
    s->top++;
    s->data[s->top]=val;
    return 0;
}

int pop(stack *s, struct node **val){
    if((s->top==-1)){
        printf("Underflow!\n");
        return 1;
    }
    *val=s->data[s->top];
    s->top--;
    return 0;
}

int isEmpty(stack *s){
    if(s->top==-1)
    return 1;
    else
    return 0;
}

stack s1;

void preorder(struct node *root){
    struct node *ptr;
    if(root==NULL){
        return;
    }
    push(&s1, root);
    while(!isEmpty(&s1)){
        pop(&s1, &ptr);
        printf("%d ", ptr->data);
        if(ptr->right!=NULL){
            push(&s1, ptr->right);
        }
        if(ptr->left!=NULL){
            push(&s1, ptr->left);
        }
    }   
}

void inorder(struct node *root){
    struct node *curr=root, *ptr;
    for(; curr!=NULL; curr=curr->left){
        push(&s1, curr);
    }
    while(!isEmpty(&s1)){
        pop(&s1, &ptr);
        printf("%d ", ptr->data);
        for(curr=ptr->right; curr!=NULL; curr=curr->left){
            push(&s1, curr);
        }
    }
}

void postorder(struct node *root){        //LOOK AT NOV 3rd video
    struct node *curr=root, *ptr, *ptr1;
    for(;curr!=NULL; curr=curr->left){
        if(curr->right!=NULL)
        push(&s1, curr->right);
        
        push(&s1, curr);
    }
    while(!isEmpty(&s1)){
        pop(&s1, &ptr);
        if(!ptr->right)
        printf("%d ", ptr->data);
        else{
            if(isEmpty(&s1))
            printf("%d ", ptr->data);
            else{
                pop(&s1, &ptr1);
                if(ptr->right!=ptr1){
                    printf("%d ", ptr->data);
                    push(&s1, ptr1);
                }
                else{
                    push(&s1, ptr);
                    for(curr=ptr1; curr!=NULL; curr=curr->left){
                        if(curr->right)
                        push(&s1, curr->right);
                        
                        push(&s1, curr);
                    }
                }
            }
        }
    }
}

struct node *createnode(int data){
    struct node *curr;
    curr=malloc(sizeof(struct node));
    curr->data=data;
    curr->left=NULL;
    curr->right=NULL;
    return curr;
}

int main(){
    struct node *root=NULL;
    init(&s1);
    root=createnode(1);
    root->left=createnode(2);
    root->right=createnode(3);
    root->left->left=createnode(4);
    root->left->right=createnode(5);
    root->right->left=createnode(6);

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}