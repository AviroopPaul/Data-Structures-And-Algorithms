// WAP Write the following menu driven program for the binary search tree
// ----------------------------------------
// Binary Search Tree Menu
// ----------------------------------------
// 0. Quit
// 1. Create
// 2. In-Order Traversal
// 3. Pre-Order Traversal
// 4. Post-Order traversal
// 5. Search
// 6. Find Smallest Element
// 7. Find Largest Element
// 8. Deletion of Tree
// ----------------------------------------
// Enter your choice:

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root = NULL;

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        struct node *curr = malloc(sizeof(struct node));
        curr->data = val;
        curr->right = curr->left = NULL;
        return curr;
    }
    if (val > root->data)
    {
        root->right = insert(root->right, val);
        return root;
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
        return root;
    }
    return root;
}

void preorder(struct node *r)
{
    if (r == NULL)
    {
        printf("No element in the BST\n");
        return;
    }

    printf("%d ", r->data); // base case

    if (r->left != NULL)
        preorder(r->left);
    if (r->right != NULL)
        preorder(r->right);
}

void inorder(struct node *r)
{
    if (r == NULL)
    {
        printf("No element in the BST. \n");
        return;
    }
    if (r->left != NULL)
    {
        inorder(r->left);
    }
    printf("%d ", r->data);
    if (r->right != NULL)
    {
        inorder(r->right);
    }
}

void postorder(struct node *r)
{
    if (r == NULL)
    {
        printf("No element present in the BST. \n");
        return;
    }
    if (r->left != NULL)
        postorder(r->left);

    if (r->right != NULL)
        postorder(r->right);

    printf("%d ", r->data);
}

struct node *search(struct node *r, int v)
{
    if (r == NULL)
    {
        printf("Value not found/Tree is empty\n");
        return r;
    }
    if (v > r->data)
    {
        return search(r->right, v);
    }
    if (v < r->data)
    {
        return search(r->left, v);
    }
    return r;
}

struct node *findMin(struct node *r)
{
    if (r == NULL)
    {
        return r;
    }
    if (r->left == NULL)
    {
        return r;
    }
    return findMin(r->left);
}

struct node *findMax(struct node *r)
{
    if (r == NULL)
        return r;

    if (r->right == NULL)
        return r;

    return findMax(r->right);
}

struct node *delete (struct node *r, int val)
{
    if (r == NULL)
        return r;
    if (val > r->data)
    {
        r->right = delete (r->right, val);
        return r;
    }
    if (val < r->data)
    {
        r->left = delete (r->left, val);
        return r;
    }
    if (val == r->data)
    {
        if (r->left != NULL && r->right != NULL)
        { // with 2 children
            struct node *curr = findMax(r->left);
            r->data = curr->data;
            r->left = delete (r->left, curr->data);
            return r;
        }
        if (r->right != NULL)
        { // with 1 child
            struct node *temp = r->right;
            free(r);
            return temp;
        }
        if (r->left != NULL)
        { // with 1 child
            struct node *temp = r->left;
            free(r);
            return temp;
        }
        free(r); // default case, no child
        return NULL;
    }
}

int main()
{
    int choice;
    printf("\n\n-------------PROGRAM FOR BINARY SEARCH TREE OPERATIONS-------------\n\n\n");
    printf("--------------MENU---------------\n");
    printf("0 -> Quit. \n");
    printf("1 -> Create. \n");
    printf("2 -> In-Order Traversal. \n");
    printf("3 -> Pre-order Traversal. \n");
    printf("4 -> Post-order Traversal \n");
    printf("5 -> Search. \n");
    printf("6 -> Find Smallest Element. \n");
    printf("7 -> Find Largest element. \n");
    printf("8 -> Delete a node. \n");
    printf("---------------------------------\n");
    do
    {
        printf("\nEnter a choice(Numeric value): \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
        {
            printf("Quitting...\n");
            break;
        }
        case 1:
        {
            int data;
            printf("Enter data: \n");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        }
        case 2:
        {
            printf("In-Order Traversal: \n");
            inorder(root);
            break;
        }
        case 3:
        {
            printf("Pre-Order Traversal: \n");
            preorder(root);
            break;
        }
        case 4:
        {
            printf("Post-Order Traversal: \n");
            postorder(root);
            break;
        }
        case 5:
        {
            int key;
            printf("Enter data to be searched for: \n");
            scanf("%d", &key);
            struct node *f = search(root, key);
            if (f)
            {
                printf("Data found!\n");
            }
            else
            {
                printf("Data not present\n");
            }
            break;
        }
        case 6:
        {
            struct node *ptr = findMin(root);
            printf("Smallest element: %d \n", ptr->data);
            break;
        }
        case 7:
        {
            struct node *ptr = findMax(root);
            printf("Largest element: %d \n", ptr->data);
            break;
        }
        case 8:
        {
            int key;
            printf("Enter element to delete: \n");
            scanf("%d", &key);
            struct node *d = delete (root, key);
            printf("Element deleted is: %d\n", d->data);
            break;
        }
        default:
        {
            printf("invalid!");
            break;
        }
        }
    } while (choice != 0);
}