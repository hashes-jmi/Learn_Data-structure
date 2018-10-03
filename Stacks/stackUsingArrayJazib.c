#include<stdio.h>
int a[5],f=-1;


void push(){
int b;
if(f==4){
    printf("Overflow\n");
    return;
}
printf("Enter the element you want to insert\n");
scanf("%d",&b);
f++;
a[f]=b;
}


void pop(){
if(f==-1){
    printf("Underflow\n");
    return;
}
f--;
}

void print(){
   int i;
   for(i=0;i<=f;i++){
       printf("%d ",a[i]);
   }
   printf("\n");
}

int main(){
int choice;
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