#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(struct node **h, int val, int pos){
    struct node *curr,*temp;
    curr=malloc(sizeof(struct node));
    curr->data=val;
    curr->next=NULL;
    if(*h==NULL)
    {
        *h=curr;
        curr->next=curr;
    }
    else if(pos==0){
        //struct node *temp;
        temp=*h;
        while(temp->next!=*h)
        temp=temp->next;
        curr->next=*h;
        *h=curr;
        temp->next=curr;
    }

    else{
        //struct node *temp;
        temp=*h;
        int i=0;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        curr->next=temp->next;
        temp->next=curr;
    }
}


void delete(struct node **h, int val){
    struct node *ptr, *prev;
    if(*h==NULL)
    printf("List is empty. \n");
    else{
        ptr=*h;
        while(ptr->next!=*h && ptr->data!=val){
            prev=ptr;
            ptr=ptr->next;
        }
        if(ptr->next==*h && ptr->data!=val){       //ptr is at the last node and the value is not found
            printf("\n\nData not found. \n");
        }
        else if(ptr==ptr->next){                   //one and only one node present in the list
            *h=NULL;        
            free(ptr);
        }
        else if(ptr==*h){                       //deleting first node of the list
            struct node *temp;
            while(temp->next!=*h)       //since it is circular, the last node needs to point to the first
            temp=temp->next;
            *h=ptr->next;
            temp->next=*h;                      //last node pointing to the first node
            free(ptr);
        }
        else{                                   //deleting node at any other place
            prev->next=ptr->next;
            free(ptr);
        }
    }
}

void display(struct node *h){
    struct node *ptr;
    if(h!=NULL){
        ptr=h;
        do{
            printf("%d ", ptr->data);
            ptr=ptr->next;
        }while(ptr!=h);
    }
    else
    printf("\nList is empty.\n");
}


int main(){
    struct node *head=NULL;
    delete(&head, 30);
    
    insert(&head, 29, 0);
    delete(&head, 29);
    display(head);

    insert(&head, 30, 1);
    insert(&head, 31, 2);
    insert(&head, 33, 3);
    
    printf("\nAfter insertion\n");
    display(head);
    
    delete(&head, 30);
    delete(&head, 34);
    
    printf("\nAfter deletion: \n");
    display(head);

}