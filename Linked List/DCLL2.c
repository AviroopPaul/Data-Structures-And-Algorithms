#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void insert(struct node **h, int data, int pos){    
    struct node *curr;
    curr=malloc(sizeof(struct node));
    curr->data=data;
    curr->next=NULL;
    curr->prev=NULL;
    if(*h==NULL){
        *h=curr->next=curr->prev=curr;
    }
    else if(pos==0){
        curr->prev=(*h)->prev;
        curr->next=(*h);
        (*h)->prev=curr;
        curr->prev->next=curr;
        *h=curr;
    }
    else{
        struct node *ptr=*h;
        int i=0;
        while(i<pos-1){
            ptr=ptr->next;
            i++;
        }
        if(ptr->next==(*h)){
            curr->prev=(*h)->prev;
            curr->next=(*h);
            (*h)->prev=curr;
            curr->prev->next=curr;
        }
        else{
            curr->prev=ptr;
            curr->next=ptr->next;
            ptr->next=curr;
            curr->next->prev=curr;
        }
    }
}


void delete(struct node **h, int val){  
    if(*h==NULL)
    printf("\nList is empty!\n");
    else{
        struct node *ptr=*h;
        while(ptr->next!=*h && ptr->data!=val){
            ptr=ptr->next;
        }
        
        if(ptr->next==*h && ptr->data!=val)
        printf("\nValue not present in the list!\n");
        else if(ptr->next==ptr){
            *h=NULL;
            free(ptr);
        }
        else if(ptr==*h){
            ptr->next->prev=ptr->prev;
            ptr->prev->next=ptr->next;
            (*h)=ptr->next;
            free(ptr);
        }
        else{
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            free(ptr);
        }
    }
}

void display(struct node *h){
    struct node *ptr=h;
    do{   
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }while(ptr!=h);
}


int main(){
    struct node *head=NULL;
    
    printf("\nDeleting 10: ");
    delete(&head, 10);
    printf("\n");
    
    insert(&head, 10, 0);
    insert(&head, 12, 1);
    insert(&head, 13, 2);
    
    display(head);

    insert(&head, 9, 0);
    printf("\n");
    display(head);
    insert(&head, 11, 2);
    printf("\n");
    display(head);
    printf("\n");
    
    delete(&head, 11);
    printf("\nDeleting 11:\n");
    display(head);
    delete(&head, 12);
    printf("\nDeleting 12:\n");
    display(head);
    printf("\nDeleting 18:");
    delete(&head, 18);
    

}
