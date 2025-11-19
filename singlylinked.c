#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}


void insertAtFront(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    if (q->front == NULL) {
        q->front = q->rear = newNode;
    } else {
        newNode->next = q->front;
        q->front = newNode;
    }
}


void insertAtRear(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}


void deleteFromFront(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL; // If the list becomes empty
    }

    free(temp);
}


void displayQueue(struct Queue* q) {
    struct Node* temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Queue q;
    initializeQueue(&q);

    insertAtFront(&q, 10);  // Insert at front
    insertAtRear(&q, 20);   // Insert at rear
    insertAtRear(&q, 30);   // Insert at rear
    insertAtFront(&q, 5);   // Insert at front

    displayQueue(&q);

    printf("Deleting from front...\n");
    deleteFromFront(&q);
    displayQueue(&q);

    return 0;
}
