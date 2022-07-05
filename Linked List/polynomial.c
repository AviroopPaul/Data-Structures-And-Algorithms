#include<stdio.h>
#include<stdlib.h>

struct node {
    int coeff;
    int expo;
    struct node *next;
};

void create(struct node **h){
    int n;
    printf("\nEnter number of terms you want to enter: \n");
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        struct node *curr=malloc(sizeof(struct node)),*t;
        printf("\nEnter Coefficient and Exponent of the term: \n");
        scanf("%d %d", &curr->coeff, &curr->expo);
        curr->next=NULL;
        if(*h==NULL){
            *h=curr;
            t=curr;
        }
        else{
            t->next=curr;
            t=curr;
        }
    }
}

void join(struct node **h1, struct node *h2){
    if(*h1==NULL)
    *h1=h2;
    else{
        struct node *ptr=*h1;
        for(;ptr->next!=NULL; ptr=ptr->next);
        ptr->next=h2;
    }
}

void simplify(struct node **h){
struct node *curr=*h, *ptr, *prev;
while(curr!=NULL){
    ptr=curr->next;
    prev=curr;
    while(ptr!=NULL){
        if(ptr->expo==curr->expo){
            curr->coeff+= ptr->coeff;
            prev->next=ptr->next;
            free(ptr);
            prev=ptr;
        }
        prev=ptr;
        ptr=ptr->next;
    }
    curr=curr->next;
}
}

void display(struct node *h){
    for(struct node *ptr=h; ptr!=NULL; ptr=ptr->next){
        printf("Coeff: %d, Exponent: %d", ptr->coeff, ptr->expo);
        printf("\n");
    }
}

int main(){
    struct node *h1=NULL, *h2=NULL;
    create(&h1);
    create(&h2);
    join(&h1, h2);
    simplify(&h1);
    display(h1);
}