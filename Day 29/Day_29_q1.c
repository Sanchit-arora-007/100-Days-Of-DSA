#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    for (int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct node* rotateRight(struct node* head, int k) {
    if (!head || k == 0) return head;

    struct node *temp = head;
    int length = 1;

    while (temp->next) {
        temp = temp->next;
        length++;
    }

    temp->next = head;

    k = k % length;
    int steps = length - k;

    struct node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(struct node* head) {
    printf("Rotated list: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node* head = createList(n);

    printf("Enter k: ");
    scanf("%d", &k);

    head = rotateRight(head, k);
    printList(head);

    return 0;
}