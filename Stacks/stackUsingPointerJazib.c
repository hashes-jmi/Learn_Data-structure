#include<stdio.h>
#include<stdlib.h>


struct node{
    int a;
    struct node *link;
}*top,*ptr;


void push(){
    int b;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element you want to insert\n");
    scanf("%d",&b);
    ptr->a=b;
    ptr->link=NULL;
    if(top==NULL)
    top=ptr;
    else {
        ptr->link=top;
        top=ptr;
    }
}


void pop(){
    struct node *ptr;
    if(top==NULL){
        printf("Underflow\n");
        return;
    }
    ptr=top;
    top = top -> link;
    free(ptr);
}

void print(){
    struct node *ptr;
    if(top==NULL){
        printf("Empty\n");
        return;
    }
    ptr=top;
    while(ptr!=NULL){
        printf("%d ",ptr->a);
        ptr=ptr->link;
    }
    printf("\n");
}

int main(){
int choice,b;
top=NULL;
do{
    printf("Enter your choice\n");
    printf("1. Push\n2. Pop\n3. Print\n4. Exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3: print();
                break;
}
}while(choice!=4);
    return 0;
}