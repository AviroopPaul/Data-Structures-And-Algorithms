#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    char TL;
    int data;
    char TR;
    struct node *right;
};

void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    struct node *curr=root;
    for( ;curr->left!=NULL; curr=curr->left);
    while(1){
        printf("%d ", curr->data);
        if(curr->TR){
            curr=curr->right;    //if threaded right is present.
        }
        else{
            curr=curr->right;
            if(curr==NULL) 
            break;
            for(; curr->left!=NULL; curr=curr->left);
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
    root= createnode(10);
    root->left= createnode(11);
    root->left->left= createnode(12);
    root->left->left->right=createnode(14);
    root->left->left->right->right=root->left;
    root->left->right=root;
    root->left->left->right->TR=1;
    root->left->TR=1;

            //      10
            //     /   
            //    11 
            //   /      
            // 12
            //   \
            //    14

    inorder(root);

}