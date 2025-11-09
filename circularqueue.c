#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        return 1;
    return 0;
}

// Check if the queue is empty
int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

// Add an element
void enQueue(int element) {
    if (isFull())
        printf("\nQueue is full!!\n");
    else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\nInserted -> %d\n", element);
    }
}

// Remove an element
int deQueue() {
    int element;
    if (isEmpty()) {
        printf("\nQueue is empty!!\n");
        return -1;
    } else {
        element = items[front];
        if (front == rear) {
            // Queue becomes empty
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("\nDeleted element -> %d\n", element);
        return element;
    }
}

// Display the queue
void display() {
    int i;
    if (isEmpty())
        printf("\nEmpty Queue\n");
    else {
        printf("\nFront -> %d", front);
        printf("\nItems -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
            printf("%d ", items[i]);
        printf("%d ", items[i]); // Print the last element
        printf("\nRear -> %d\n", rear);
    }
}

// Main function with menu
int main() {
    int choice, element;

    printf("=== Circular Queue Implementation ===\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                enQueue(element);
                break;

            case 2:
                deQueue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
