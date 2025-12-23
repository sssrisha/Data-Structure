#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

typedef struct node* NODE;
NODE head = NULL;


NODE createNode(int value)
{
    NODE newnode;

    newnode = (NODE)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }

    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}


void insertFront(int value)
{
    NODE newnode;

    newnode = (NODE)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = value;
    newnode->next = head;
    head = newnode;
}


void insertRear(int value)
{
    NODE newnode = createNode(value);

    if (head == NULL) {
        head = newnode;
        return;
    }

    NODE temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}


void insertAtPos(int value, int pos)
{
    NODE newnode, temp;

    if (pos == 1) {
        insertFront(value);
        return;
    }

    newnode = createNode(value);
    temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}


void insertAfterPos(int value, int pos)
{
    NODE newnode, temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    newnode = createNode(value);
    newnode->next = temp->next;
    temp->next = newnode;
}


void insertBeforePos(int value, int pos)
{
    NODE newnode, temp;

    if (pos == 1) {
        insertFront(value);
        return;
    }

    newnode = createNode(value);
    temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}


void deleteFront()
{
    NODE temp;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}


void deleteRear()
{
    NODE temp;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}


void deleteAtPos(int pos)
{
    NODE temp, del;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    if (pos == 1) {
        deleteFront();
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);
}


void deleteAfterPos(int pos)
{
    NODE temp = head, del;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Deletion not possible\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);
}


void deleteBeforePos(int pos)
{
    NODE temp, del;

    if (pos <= 1 || head == NULL) {
        printf("Deletion not possible\n");
        return;
    }

    if (pos == 2) {
        deleteFront();
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 2 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL || temp->next->next == NULL) {
        printf("Deletion not possible\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);
}

void display()
{
    NODE temp = head;
    printf("SLL: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main()
{
    int choice, value, pos;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Insert At Position\n");
        printf("4. Insert After Position\n");
        printf("5. Insert Before Position\n");
        printf("6. Delete Front\n");
        printf("7. Delete Rear\n");
        printf("8. Delete At Position\n");
        printf("9. Delete After Position\n");
        printf("10. Delete Before Position\n");
        printf("11. Display\n");
        printf("12. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: scanf("%d", &value);
                insertFront(value); 
                break;
            case 2: scanf("%d", &value); 
                insertRear(value); 
                break;
            case 3: scanf("%d %d", &value, &pos);
                insertAtPos(value, pos); 
                break;
            case 4: scanf("%d %d", &value, &pos); 
                insertAfterPos(value, pos); 
                break;
            case 5: scanf("%d %d", &value, &pos); 
                insertBeforePos(value, pos); 
                break;
            case 6: deleteFront();
                break;
            case 7: deleteRear();
                break;
            case 8: scanf("%d", &pos); 
                deleteAtPos(pos);
                break;
            case 9: scanf("%d", &pos); 
                deleteAfterPos(pos); 
                break;
            case 10: scanf("%d", &pos);
                deleteBeforePos(pos); 
                break;
            case 11: display();
                break;
            case 12: exit(0);
            
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
