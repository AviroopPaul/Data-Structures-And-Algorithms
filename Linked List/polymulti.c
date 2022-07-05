#include<stdio.h>
#include<stdlib.h>

struct node {
    int coeff;
    int expo;
    struct node *next;
};

void *multi(struct node **h1, struct node **h2){
    struct node *newhead=NULL, *newtail=NULL;
    for(;(*h1)!=NULL; (*h1)=(*h1)->next){
        for(struct node *ptr=(*h2); ptr!=NULL; ptr=ptr->next){
            struct node *curr=malloc(sizeof(struct node));
            curr->next=NULL;
            curr->coeff= (*h1)->coeff * ptr->coeff;
            curr->expo=(*h1)->expo + ptr->expo;
            if(newhead==NULL){                
                newhead=curr;
                newtail=curr;
            }
            else{
                newtail->next=curr;
                newtail=curr;
            }
        }
    }
    struct node *ptr=newhead, *ptr1, *prev;
    while(ptr!=NULL){
        ptr1=ptr->next;
        prev=ptr;
        while(ptr1!=NULL){
            if(ptr1->expo==ptr->expo){
                ptr->coeff += ptr1->coeff;
                prev->next=ptr1->next;
                free(ptr1);
                ptr1=prev;
            }
            prev=ptr1;
            ptr1=ptr1->next;
        }
        ptr=ptr->next;
    }
    return newhead;
}


void create(struct node **h){
    int n;
    printf("Enter the number many terms you want to enter: \n");
    scanf("%d", &n);
    for( int i=0; i<n; i++){
        struct node *curr=malloc(sizeof(struct node)), *tail;
        printf("Coefficient: \n Exponent: \n");
        scanf("%d %d", &curr->coeff, &curr->expo);
        curr->next=NULL;
        if(*h==NULL){
            *h=curr;
            tail=curr;
        }
        else{
            tail->next=curr;
            tail=curr;
        }
    }
}

void display(struct node *h){
    for(struct node *ptr=h; ptr!=NULL; ptr=ptr->next){
        printf("Coeff: %d, Exponent: %d", ptr->coeff, ptr->expo);
        printf("\n");
    }
}

int main(){
    struct node *h1=NULL, *h2=NULL, *nhead=NULL;
    create(&h1);
    create(&h2);
    printf("\nFirst polynomial: \n");
    display(h1);
    printf("\nSecond polynomial: \n");
    display(h2);
    nhead=multi(&h1, &h2);
    printf("\nPolynomial after multiplying: \n");
    display(nhead);
}

