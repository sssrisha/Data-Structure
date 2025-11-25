#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void beginsert();
void lastinsert();
void randominsert();
void insert_at_position();
void insert_after_data();
void begin_delete();
void last_delete();
void random_delete();
void search();
void display();
void length();   // NEW

int main() {
    int choice = 0;

    while (choice != 12) {
        printf("\n********** Main Menu **********\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at last\n");
        printf("3. Insert at any random location (after position)\n");
        printf("4. Insert at a particular position\n");
        printf("5. Insert after a particular data\n");
        printf("6. Delete from beginning\n");
        printf("7. Delete from last\n");
        printf("8. Delete node after specified location\n");
        printf("9. Search for an element\n");
        printf("10. Show list\n");
        printf("11. Length of the list\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: beginsert();
             break;
            case 2: lastinsert();
             break;
            case 3: randominsert();
            break;
            case 4: insert_at_position();
             break;
            case 5: insert_after_data();
            break;
            case 6: begin_delete();
             break;
            case 7: last_delete();
             break;
            case 8: random_delete();
            break;
            case 9: search();
             break;
            case 10: display();
            break;
            case 11: length();
            break;
            case 12: printf("Exiting...\n");
             break;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void beginsert() {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    int item;

    printf("Enter value to insert: ");
    scanf("%d", &item);

    ptr->data = item;
    ptr->next = head;
    head = ptr;

    printf("Node inserted at beginning!\n");
}

void lastinsert() {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    int item;

    printf("Enter value to insert: ");
    scanf("%d", &item);

    ptr->data = item;
    ptr->next = NULL;

    if (head == NULL) {
        head = ptr;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }

    printf("Node inserted at end!\n");
}

void randominsert() {
    int loc, item;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;

    printf("Enter value: ");
    scanf("%d", &item);
    printf("Enter location to insert after: ");
    scanf("%d", &loc);

    temp = head;
    for (int i = 1; i < loc; i++) {
        if (temp == NULL) {
            printf("Location not found!\n");
            return;
        }
        temp = temp->next;
    }

    ptr->data = item;
    ptr->next = temp->next;
    temp->next = ptr;

    printf("Node inserted after location %d!\n", loc);
}

void insert_at_position() {
    int pos, item;
    struct node *ptr, *temp;

    printf("Enter position to insert at: ");
    scanf("%d", &pos);

    printf("Enter value: ");
    scanf("%d", &item);

    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = item;
    ptr->next = NULL;

    if (pos == 1) {
        ptr->next = head;
        head = ptr;
        printf("Node inserted at position 1!\n");
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position does not exist!\n");
            return;
        }
        temp = temp->next;
    }

    ptr->next = temp->next;
    temp->next = ptr;

    printf("Node inserted at position %d!\n", pos);
}

void insert_after_data() {
    int target, item;
    struct node *ptr, *temp;

    printf("Enter data after which to insert: ");
    scanf("%d", &target);

    printf("Enter value to insert: ");
    scanf("%d", &item);

    temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Data not found!\n");
        return;
    }

    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = item;
    ptr->next = temp->next;
    temp->next = ptr;

    printf("Node inserted after data %d!\n", target);
}

void begin_delete() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *ptr = head;
    head = head->next;
    free(ptr);

    printf("Node deleted from beginning!\n");
}

void last_delete() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = head, *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
        head = NULL;
    else
        prev->next = NULL;

    free(temp);

    printf("Node deleted from end!\n");
}

void random_delete() {
    int loc;
    struct node *temp = head, *ptr;

    printf("Enter location after which node should be deleted: ");
    scanf("%d", &loc);

    for (int i = 1; i < loc; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Location not found!\n");
            return;
        }
        temp = temp->next;
    }

    ptr = temp->next;
    temp->next = ptr->next;
    free(ptr);

    printf("Node deleted!\n");
}

void search() {
    int item, pos = 1;
    struct node *temp = head;

    printf("Enter element to search: ");
    scanf("%d", &item);

    while (temp != NULL) {
        if (temp->data == item) {
            printf("Element %d found at position %d\n", item, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element not found!\n");
}

void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void length() {
    int count = 0;
    struct node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Length of the linked list = %d\n", count);
}

