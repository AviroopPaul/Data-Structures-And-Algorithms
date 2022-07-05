// 1. Construct a tree and write the functions for the following subproblems
// a) To count number of leaf nodes in the tree.
// b) To count number of non-leaf nodes in the tree.
// c) To find number of nodes in the tree.
// d) To find sum of all nodes of the tree.
// e) To print depth of the tree.
// f) To find nodes which are at maximum depth in the tree?
// g) To print all the elements of kth level in single line.
// h) To find the common ancestor and print the paths.
// i) To check whether a tree is a binary search tree or not.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
}*root =NULL;

struct nodequeue {
    struct node *qdata;
    struct nodequeue *next;
};

typedef struct{
    struct nodequeue *front;
    struct nodequeue *rear;
}queue;

void init(queue *q){
    q->front=q->rear=NULL;
}

int insert(queue *q, struct node* val){
    struct nodequeue *curr=malloc(sizeof(struct node));
    if(curr==NULL)
    {
        printf("Insertion not possible\n");
        return 1;
    }
    curr->qdata=val;
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

int delete(queue *q, struct node **val){
    if(q->front==NULL){
        printf("Deletion is not possible, Queue empty.\n");
        return 1;
    }
    if(q->rear==q->front){
        *val=q->front->qdata;
        q->rear=q->front=NULL;
    }
    else{
        *val=q->front->qdata;
        struct nodequeue *ptr=q->front;
        q->front=q->front->next;
        free(ptr);
    }
    return 0;
}

int isEmptyQueue(queue *q){
    if(q->front==NULL && q->rear==NULL)
    return 0;
    else 
    return 1;
}

int leafNodeCount(struct node *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return (leafNodeCount(root->left) + leafNodeCount(root->right));
}

int nonLeafNodeCount(struct node *root){
    if(root==NULL || (root->left==NULL && root->right==NULL))
    return 0;

    return 1 + nonLeafNodeCount(root->left) + nonLeafNodeCount(root->right);
}

int NumOfNodes(struct node *root){
    if(root==NULL){
        return 0;
    }
    return 1 + (NumOfNodes(root->left) + NumOfNodes(root->right));
}

int SumofNodes(struct node *root){
    if(root==NULL){
        return 0;
    }
    return root->data + (SumofNodes(root->left)+SumofNodes(root->right));
}

int depthOfTree(struct node *root){
    if(root==NULL){
        return -1;
    }
    int leftHt=depthOfTree(root->left);
    int rightHt=depthOfTree(root->right);
    if(leftHt>rightHt)
    return leftHt+1;
    else
    return rightHt+1;
}

int levelOrderTraversal(struct node *root){
    if(root==NULL)
    return 0;
    
    queue q;
    init(&q);
    insert(&q, root);
    insert(&q, NULL);

    while(q.front!=NULL){
        struct node *ptr=q.front->qdata;
        struct node *k;
        delete(&q, &k);
        if(ptr!=NULL){
            printf("%d ", ptr->data);
            if(ptr->left)
            insert(&q, ptr->left);
            if(ptr->right)
            insert(&q, ptr->right);
        }
        else if(isEmptyQueue(&q))
        insert(&q, NULL);
    }
}

int nodesAtDeepestLevel(struct node *root){
    if(root==NULL)
    return 0;
    
    queue q; int level=0;
    init(&q);
    insert(&q, root);
    insert(&q, NULL);
    
    while(isEmptyQueue(&q)){
        struct node *ptr=q.front->qdata;
        struct node *k;
        delete(&q, &k);
        
        if(ptr!=NULL){
            if(level==depthOfTree(root))
            printf("%d ", ptr->data);
            if(ptr->left)
            insert(&q, ptr->left);
            if(ptr->right)
            insert(&q, ptr->right);
        }
        else if(isEmptyQueue(&q)){
            insert(&q, NULL);
            level++;
        }
    }
}

int nodesAtKthLevel(struct node *root, int lvl){
    if(root==NULL)
    return 0;
    
    int level=0;
    queue q; 
    init(&q);
    insert(&q, root);
    insert(&q, NULL);

    while(isEmptyQueue(&q)){
        struct node *ptr=q.front->qdata;
        struct node *k;
        delete(&q, &k);
        if(ptr!=NULL){
            if(level==lvl){
                printf("%d ", ptr->data);
            }
            if(ptr->left)
            insert(&q, ptr->left);
            if(ptr->right)
            insert(&q, ptr->right);
        }
        else if(isEmptyQueue(&q)){
            insert(&q, NULL);
            level++;
        }
    }
}

int LowestCommonAncestor(struct node *root, int n1, int n2){
     
}

int isBST(struct node *root, int min, int max){
    if(root==NULL)
    return 1;
    if(root->data<min || root->data>max)
    return 0;
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
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
    root->right=createnode(13);
    root->left=createnode(8);
    root->left->left=createnode(7);
    root->left->right=createnode(9);
    root->right->left=createnode(12);
    root->right->right=createnode(14);

            //         10
            //        /   \
            //       8     13
            //     /  \   /  \
            //    7    9 12  14


    printf("Number of leaf nodes: %d \n", leafNodeCount(root));
    printf("Number of non-leaf nodes: %d \n", nonLeafNodeCount(root));
    printf("Number of nodes: %d \n", NumOfNodes(root));
    printf("Sum of nodes: %d \n", SumofNodes(root));
    printf("Depth of tree: %d \n", depthOfTree(root));
    printf("Level Order Traversal of the tree: \n");
    levelOrderTraversal(root);
    printf("\nNodes at deepest level of tree: \n");
    nodesAtDeepestLevel(root);
    printf("\nNodes at the 1st level: \n");
    nodesAtKthLevel(root, 1);
    printf("\nIs the given Tree a Binary Search Tree? \n");
    if(isBST(root, -100 , 100))
    printf("Yes.\n");
    else
    printf("No.\n");
}