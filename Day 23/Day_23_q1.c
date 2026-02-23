#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy.next;
}

void printList(struct Node* head) {
    printf("Merged list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    struct Node *list1 = NULL, *list2 = NULL;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first sorted list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(&list1, x);
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second sorted list: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        append(&list2, x);
    }

    struct Node* merged = mergeLists(list1, list2);
    printList(merged);

    return 0;
}