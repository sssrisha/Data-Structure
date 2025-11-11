
#include<stdio.h>

#define size 10
void push(int);
void pop();
void display();
int stack[size],top=-1;
void main(){
int value,choice;

while(1){
    printf("\n*****MENU******\n");
    printf("1.push\n 2.pop\n 3.display\n 4.exit");
    printf("enter your choice");
    scanf("%d",&choice);
    switch (choice){
      case 1 :printf("enter the value to be inserted\n");
                scanf("%d",&value);
                printf(value);
                break;
      case 2:pop();
                break;
      case 3: display();
                break ;
      case 4:exit(0);
                break;
      default : printf("wrong selection try aggain");
    }}}
void push(int value){
    top=-1;
    stack[size];
    if (top==size-1)
        printf("stack is full!!insertion is not possible");
    else {
        top++;
        stack[top]=value;
        printf("insertion successfull!");

    }
    void pop(){
 if (top==-1)
    printf("stack is empty!!deletion is not possible");
 else
    printf("deleted: %d",stack[top]);
    top--;


}
void display(){
 if (top==-1)
    printf("stack is empty!!");
 else{
    int i;
    printf("stack element are\n");
    for(i=top;i>0;i--){

        printf("%d",stack[i]);

    }

 }

}

}
