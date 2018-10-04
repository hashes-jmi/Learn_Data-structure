#include<stdio.h>
#include<stdlib.h>


struct node{
    int a;
    struct node *link;
}*front,*ptr,*rear;


void push(){
    int b;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element you want to insert\n");
    scanf("%d",&b);
    ptr->a=b;
    ptr->link=NULL;
    if(front==NULL&&rear==NULL){
        front=ptr;
        rear=ptr;
    }
    else {
        rear->link=ptr;
        rear=ptr;
    }
}


void pop(){
    struct node *ptr;
    if(front==NULL&&rear==NULL){
        printf("Underflow\n");
        return;
    }
    if(front==rear){
    ptr=front;
    free(ptr);
    front=NULL;
    rear=NULL;
    }
    else {
        ptr=front;
        front=front->link;
        free(ptr);
    }
}

void print(){
    struct node *ptr;
    if(front==NULL){
        printf("\nEmpty\n\n");
        return;
    }
    ptr=front;
    printf("\n");
    while(ptr!=NULL){
        printf("%d ",ptr->a);
        ptr=ptr->link;
    }
    printf("\n\n");
}

int main(){
int choice,b;
front=NULL;
rear=NULL;
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