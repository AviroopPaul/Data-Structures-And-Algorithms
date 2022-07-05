#include<stdio.h>
#include<stdlib.h>

struct node{
    int row;
    int col;
    int val;
    struct node *next;
};

void create(struct node **head){
    struct node *ptr=NULL;
    
    *head=malloc(sizeof(struct node));
    
    printf("\nEnter number of rows: \n");
    scanf("%d", &(*head)->row);
    printf("\nEnter number of columns: ");
    scanf("%d", &(*head)->col);
    printf("\nEnter number of non zero elements: \n");
    scanf("%d", &(*head)->val);
    
    (*head)->next=NULL;
    ptr=*head;
    
    for(int i=0; i<(*head)->val; i++){
        struct node *curr=malloc(sizeof(struct node));
        printf("\nEnter row, column and value:");
        scanf("%d %d %d", &curr->row, &curr->col, &curr->val);
        curr->next=NULL;
        ptr->next=curr;
        ptr=curr;
    }
}

void add(struct node *h1, struct node *h2, struct node **h){
    
    if(h1->row!= h2->row || h1->col!=h2->col){
        printf("\nAddtion not possible!!");
        return;
    }
    struct node *ptr=NULL;
    *h=malloc(sizeof(struct node));
    (*h)->row=h1->row;
    (*h)->col=h2->col;
    (*h)->val=h1->val+h2->val;
    (*h)->next=NULL;
    ptr=*h;

    struct node *ptr1=NULL;
    for(ptr1=h1->next; ptr1!=NULL; ptr1=ptr1->next){
        struct node *curr=malloc(sizeof(struct node));
        curr->row=ptr1->row;
        curr->col=ptr1->col;
        curr->val=ptr1->val;
        // instead of the above block of code, could write this: *curr=*ptr1; //
        curr->next=NULL;
        ptr->next=curr;
        ptr=curr;
    }
    
    for(ptr1=h2->next; ptr1!=NULL; ptr1=ptr1->next){
        struct node *curr=malloc(sizeof(struct node));
        (*curr)=(*ptr1);
        curr->next=NULL;
        ptr->next=curr;
        ptr=curr;
    }

    ptr=(*h)->next; ptr1=NULL; struct node *prev=NULL;
    while(ptr!=NULL){
        ptr1=ptr->next;
        prev=ptr;
        while(ptr1!=NULL){
            if(ptr1->row==ptr->row && ptr1->col==ptr->col)
            {
                ptr->val+=ptr1->val;
                prev->next=ptr1->next;
                free(ptr1);
                ptr1=prev;
                (*h)->val--;
            }
            prev=ptr1;
            ptr1=ptr1->next;
        }
        ptr=ptr->next;
    }
} 

void transpose(struct node *h){
    struct node *ptr=h;
    for(; ptr!=NULL; ptr=ptr->next){
        int temp=ptr->row;
        ptr->row=ptr->col;
        ptr->col=temp;
    }
}

void multiply(struct node *h1, struct node *h2, struct node **h){
    if(h1->col!=h2->row)
    printf("Multipl ication is not possible!!\n");
    
    //MULTIPLICATION CODE
    
    else
    {
        struct node *ptr;
        *h=malloc(sizeof(struct node));
        (*h)->row=h1->row;
        (*h)->col=h2->col;
        (*h)->val=0;
        (*h)->next=NULL;
        ptr=*h;    
        for(struct node *ptr1=h1->next; ptr1!=NULL; ptr1=ptr1->next){
            for(struct node *ptr2=h2->next; ptr2!=NULL; ptr2=ptr2->next){
                    if(ptr1->col==ptr2->row){
                        struct node *curr=malloc(sizeof(struct node));
                        curr->row=ptr1->row;
                        curr->col=ptr2->col;
                        curr->val=ptr1->val * ptr2->val;
                        curr->next=NULL;
                        (*h)->val++;
                        ptr->next=curr;
                        ptr=curr;
                    }
            }
        }
        
        //SIMPLICATION PART
        
        ptr=(*h)->next;
        struct node *prev, *ptr1;
        while(ptr!=NULL){
            prev=ptr;
            ptr1=ptr->next;
            while(ptr1!=NULL){
                if(ptr1->row==ptr->row && ptr1->col==ptr->col){
                    ptr->val+=ptr1->val;
                    prev->next=ptr1->next;
                    free(ptr1);
                    (*h)->val--;
                    ptr1=prev;
                }
                prev=ptr1;
                ptr1=ptr1->next;
            }
            ptr=ptr->next;
        }
    }
}

void display(struct node *he){
    for(struct node *ptr=he; ptr!=NULL; ptr=ptr->next)
    printf("%d %d %d -> ", ptr->row, ptr->col, ptr->val);
    printf("NULL\n");
}


int main(){
    struct node *h1, *h2, *h;
    create(&h1);
    create(&h2);
    
    printf("\nFirst Matrix: \n");
    display(h1);

    /*printf("After transposing: \n");
    transpose(h1);
    display(h1);*/
    
    printf("\nSecond Matrix: \n");
    display(h2);
    
    /*printf("After Addition: \n");
    add(h1, h2, &h);
    display(h);*/
    printf("\nAfter multiplication: \n");
    multiply(h1, h2, &h);
    display(h);

    
}