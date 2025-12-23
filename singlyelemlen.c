#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node* NODE;

NODE createNode(int value) {
    NODE newnode = (NODE)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

NODE insertRear(NODE head, int value) {
    NODE newnode = createNode(value);

    if (head == NULL)
        return newnode;

    NODE temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

void display(NODE head) {
    NODE temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int length(NODE head) {
    int count = 0;
    NODE temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

NODE concatenate(NODE head1, NODE head2) {
    if (head1 == NULL)
        return head2;

    NODE temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

NODE merge(NODE head1, NODE head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    NODE result = NULL;

    if (head1->data < head2->data) {
        result = head1;
        result->next = merge(head1->next, head2);
    } else {
        result = head2;
        result->next = merge(head1, head2->next);
    }

    return result;
}

NODE reverse(NODE head) {
    NODE prev = NULL;
    NODE curr = head;
    NODE next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    NODE head1 = NULL, head2 = NULL, head3 = NULL;
    int n, value;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertRear(head1, value);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head2 = insertRear(head2, value);
    }

    printf("\nList 1: ");
    display(head1);
    printf("Length of List 1 = %d\n", length(head1));

    printf("\nList 2: ");
    display(head2);
    printf("Length of List 2 = %d\n", length(head2));

    head3 = concatenate(head1, head2);
    printf("\nAfter Concatenation: ");
    display(head3);
    printf("Length after Concatenation = %d\n", length(head3));

    head3 = reverse(head3);
    printf("\nAfter Reversal: ");
    display(head3);
    printf("Length after Reversal = %d\n", length(head3));

    return 0;
}
