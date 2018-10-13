#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* Insert(struct Node* root,int data)
{
    if(root == NULL)
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        (*temp).data = data;
        (*temp).left = NULL;
        (*temp).right = NULL;
        root = temp;
    }
    else if(data <= (*root).data)
    {
        (*root).left = Insert((*root).left,data);
    }
    else if(data >= (*root).data)
    {
        (*root).right = Insert((*root).right,data);
    }
    return root;
}
bool search(struct Node* root,int data)
{
    if(root == NULL)
    return false;
    else if((*root).data == data)
    return true;
    else if(data <= (*root).data)
    return search((*root).left,data);
    else
    return search((*root).right,data);
}
int main()
{
    struct Node* root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
    int x;
    printf("Enter no. to search\n");
    scanf("%d",&x);
    if(search(root,x))
    printf("found\n");
    else
    printf("not found\n");
    return 0;
}