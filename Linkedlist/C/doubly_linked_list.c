#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;
struct Node* GetNode(int x){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void InsertAtHead(int x){
    struct Node* newNode = GetNode(x);
    if(head==NULL){
        head = newNode;
        return ;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode; 
    
}
void InsertAtTail(int x){
    struct Node* temp = head;
    struct Node* newNode = GetNode(x);
    if(head == NULL){
        head = newNode;
        return ;
    }
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
void Print(){
    struct Node* temp = head;
    printf("Forward: ");
    while(temp !=NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void ReversePrint() {
	struct Node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
int main(){
    head = NULL;
    InsertAtTail(2); Print(); ReversePrint();
	InsertAtTail(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
	InsertAtTail(8); Print(); ReversePrint();

}