#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

// -------- Check if FULL --------
int isFull() {
    return ((front == (rear + 1) % SIZE));
}

// -------- Check if EMPTY --------
int isEmpty() {
    return (front == -1);
}

// -------- INSERT FRONT --------
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is FULL!\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE;  // Wrap around backward
    }

    deque[front] = value;
}

// -------- INSERT REAR --------
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is FULL!\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;  // Wrap forward
    }

    deque[rear] = value;
}

// -------- DELETE FRONT --------
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is EMPTY!\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear) { // Only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// -------- DELETE REAR --------
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is EMPTY!\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear) { // Only one element
        front = rear = -1;
    } else {
        rear = (rear - 1 + SIZE) % SIZE;
    }
}

// -------- DISPLAY --------
void display() {
    if (isEmpty()) {
        printf("Deque is EMPTY!\n");
        return;
    }

    printf("Deque Elements: ");
    int i = front;

    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// -------- MAIN MENU --------
int main() {
    int choice, value;

    while (1) {
        printf("\n--- DOUBLE ENDED QUEUE MENU ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
