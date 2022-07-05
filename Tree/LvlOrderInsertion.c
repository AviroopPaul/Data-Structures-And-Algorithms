#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node * insertlvl(int arr[],struct node *root, int i, int n){
    if(i<n){
        struct node *curr=malloc(sizeof(arr[i]));
        root=curr;
        root->left=insertlvl(arr, root->left, 2*i+1,n);
        root->right=insertlvl(arr, root->right, 2*i+2, n);
    }
    return root;
}

void preorder(struct node *r){
    if(r==NULL){
        printf("No element in the BST\n");
        return;
    }
    
    printf("%d ", r->data); //base case
    
    if(r->left!=NULL)
    preorder(r->left);
    if(r->right!=NULL)
    preorder(r->right);
}

int main(){
    struct node *root;
    int arr[6]={1,2,3,4,5,6};
    insertlvl(arr,root,0,6);
    preorder(root);
}