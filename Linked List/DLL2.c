#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prv;
};

void insert(struct node **h, int val, int pos){
    
    struct node *curr, *ptr;
    curr=malloc(sizeof(struct node));
    curr->data=val;
    curr->next=curr->prv=NULL;
    
    if(*h==NULL){
        *h=curr;
    }
    else if(pos==0){
        curr->next=*h;
        (*h)->prv=curr;
        *h=curr;
    }
    
    else{
        ptr=*h; 
        int i=0;
        while(i<pos-1 && ptr->next!=NULL){  //while loop used to move the ptr to the desired location 
            i++;
            ptr=ptr->next;
        }
        if(ptr->next==NULL)  //insertion at the end
        {
            curr->prv=ptr;
            ptr->next=curr;
        }
        else{
            curr->prv=ptr;
            curr->next=ptr->next;
            ptr->next=curr;
            curr->next->prv=curr;
        }

    }

}


void display(struct node *h){
    for(;h!=NULL; h=h->next){
        printf("%d ", h->data);
    }
}

void delete(struct node **h, int val){
    
    struct node *ptr;
    if(*h==NULL)
    printf("Node is empty\n");
    else{
        ptr=*h;
        while(ptr!=NULL){
            if(ptr->data==val)
            break;
            ptr=ptr->next;
        }
        if(ptr==NULL){
            printf("\nValue not found. \n");
        }
        else if(*h==ptr){                   //first node with other nodes present
            *h=(*h)->next;
            (*h)->prv==NULL;
            free(ptr);
        }

        else if(*h==ptr && ptr->next==NULL){            //first and only node
            *h=NULL;
            free(ptr);
        }

        else if(ptr->next==NULL){               //last node
            ptr->prv->next=NULL;
            free(ptr);
        }
        else{                                   //any other node
            ptr->next->prv=ptr->prv;
            ptr->prv->next=ptr->next;
            free(ptr);
        }
    }
}


int main(){
    struct node *head=NULL;
    
    insert(&head, 29, 0);
    insert(&head, 31, 1);
    insert(&head, 32, 2);
    insert(&head, 33, 3);
    display(head);
    insert(&head, 30, 1);
    printf("\nAfter insertion: \n");
    display(head);
    delete(&head, 60);                  //not present in list
    delete(&head, 31);
    printf("After deletion: \n");
    display(head);
}   