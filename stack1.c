#include<stdio.h>
#define MAX 10
int stack[MAX];
int top1= -1;
int top2= MAX;

    int val;
    void push1(val){
    if (top1 < top2-1)
        stack[++top1]=val;
    else
        printf("Stack overflow in stack1\n");
    }

    void push2(val){
    if (top1 < top2-1)
        stack[--top2]=val;
    else
        printf("Stack overflow in stack2\n");
    }

    int pop1(){
    if (top1 >=0)
        return stack[top1--];
    printf("Stack1 is underflow/n");
    return -1;
    }

    int pop2() {
    if (top2 <MAX)
    return stack[top2++];
    printf("Stack2 is underflow/n");
    return -1;
    }

    void display() {
        printf("Stack1\n");
    if (top1 == -1)
        printf("Stack empty");
    else
    for (int i=0;i <=top1; i++)
     printf("%d", stack[i]);

        printf("Stack2\n");
        if (top2 ==MAX)
            printf("Empty");
        else
            for (int i=MAX-1; i>= top2;i--)
            printf("%d", stack[i]);
    }
    int main() {
    int choice, val;

    while (1) {
        printf("\n--- Two Stacks in One Array ---\n"
               "1. Push in Stack1\n"
               "2. Push in Stack2\n"
               "3. Pop from Stack1\n"
               "4. Pop from Stack2\n"
               "5. Display both stacks\n"
               "6. Exit\n"
               "Enter your choice: ");
        scanf("%d", &choice);
              switch (choice) {
        case 1:
            printf("Enter value to push in Stack1: ");
            scanf("%d", &val);
            push1(val);
            break;
        case 2:
            printf("Enter value to push in Stack2: ");
            scanf("%d", &val);
            push2(val);
            break;
        case 3:
            val = pop1();
            if (val != -1) printf("Popped from Stack1: %d\n", val);
            break;
        case 4:
            val = pop2();
            if (val != -1) printf("Popped from Stack2: %d\n", val);
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}




