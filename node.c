#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL;
    struct node *n1, *n2, *n3;

    
    n1 = (struct node*)malloc(sizeof(struct node));
    n2 = (struct node*)malloc(sizeof(struct node));
    n3 = (struct node*)malloc(sizeof(struct node));

 
    printf("Enter value for node 1: ");
    scanf("%d", &n1->data);

    printf("Enter value for node 2: ");
    scanf("%d", &n2->data);

    printf("Enter value for node 3: ");
    scanf("%d", &n3->data);

 
    head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

   
    struct node* temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}


