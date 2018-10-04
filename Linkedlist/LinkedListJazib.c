#include<stdio.h>
#include<stdlib.h>

int count=0;

struct node{
    int a;
    struct node *link;
}*head,*ptr;


void push(){
    printf("Current count is %d\n",count);
    int b,pos,i;
    ptr=(struct node*)malloc(sizeof(struct node));
    struct node *current;
    struct node *prev;
    printf("Enter the element you want to insert\n");
    scanf("%d",&b);
    printf("Enter the position\n");
    scanf("%d",&pos);
    if(pos>count+1||pos<0){
        printf("Position does not exist\n");
        return;
    }  
    ptr->a=b;
    ptr->link=NULL;

    if(head==NULL){
        head=ptr;
        count++;
    }

    else{
        if(pos==1){
            ptr->link=head;
            head=ptr;
            count++;
        }

        else{
            current=head;
            for(i=1;i<=count;i++){
                if(pos-1==i){
                    ptr->link=current->link;
                    current->link=ptr;
                    count++;
                    break;
                }
                current=current->link;
            }
        }
    }
}


void pop(){
    int pos,i;
    struct node *current;
    if(head==NULL){
        printf("Underflow\n");
        return;
    }
    printf("Enter the position\n");
    scanf("%d",&pos);

    if(pos>count||pos<0){
        printf("Position does not exist\n");
        return;
    } 

    if(pos==1){
        ptr=head;
        head=head->link;
        free(ptr);
        count--;
    } 
    else {
        current=head;
        for(i=1;i<=count;i++){
            if(pos-1==i){
                ptr=current->link;
                current->link=current->link->link;
                free(ptr);
                count--;
                break;
            }
            current=current->link;
        }
    }
}

void print(){
    if(head==NULL){
        printf("\nEmpty\n\n");
        return;
    }
    ptr=head;
    printf("\n");
    while(ptr!=NULL){
        printf("%d ",ptr->a);
        ptr=ptr->link;
    }
    printf("\n\n");
}

void rev(){
    struct node *current;
    struct node *prev;
    struct node *next;
    prev=NULL;
    current=head;
    next=head;
    while(current!=NULL){
        next=next->link;
        current->link=prev;
        prev = current;
        current = next;
    }
    head=prev;

}

int main(){
int choice;
do{
    printf("Enter your choice\n");
    printf("1. Push\n2. Pop\n3. Reverse\n4. Print\n5. Exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3: rev();
                break;
        case 4: print();
                break;
}
}while(choice!=5);
    return 0;
}