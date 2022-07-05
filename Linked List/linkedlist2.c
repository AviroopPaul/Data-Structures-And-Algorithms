#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};


void initialise(struct node **h, int n){
        
        struct node *ptr, *curr;
        curr= malloc(n*sizeof(struct node));
        curr->next=NULL;
        curr->data=rand()%100;
        if(*h==NULL){
            *h=curr;
        }
        else{
            ptr=*h;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=curr;
        }
}


void insert(struct node **he,int data, int pos){
    struct node *cur;
    cur=malloc(sizeof(struct node));
    cur->data=data;
    cur->next=NULL;
    if(*he==NULL)
    {
        *he=cur;
    }
    else{
        struct node *ptr;
        ptr=*he; int i=0;
        while(i<pos-1 && ptr->next!=NULL){
            ptr=ptr->next;
            i++;
        }
        cur->next=ptr->next;
        ptr->next=cur;
    }
}


void delete (struct node **h, int v){
    struct node *ptrr,*prv;
    if(*h==NULL)
    printf("List is Empty");
    else{
        ptrr=*h;
        while(ptrr!=NULL){
            if(ptrr->data==v)
            break;
            else{
                prv=ptrr;
                ptrr=ptrr->next;
            }
        }
            if(ptrr==NULL)
            printf("Value not present in the list.\n");
            else if(ptrr==*h){   //value is present in the first node thus changing head
                *h=ptrr->next;
                free(ptrr);
            }
            else{                       //value present at any other node
                prv->next=ptrr->next;
                free(ptrr);
            }

        }
}


void display(struct node *h){
    for(;h!=NULL; h=h->next)
    printf("%d ", h->data);
}


int main()
{
    int n;
    scanf("%d", &n);
    struct node *head=NULL;
    for(int i=0;i<n;i++)
    {
        initialise(&head,n);
    }
    
    insert(&head,20, 7);
    display(head); //before deletion
    delete(&head, 34);
    printf("\n");
    display(head); //after deletion
}