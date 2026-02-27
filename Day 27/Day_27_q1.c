#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (!head) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

int main() {
    int n, m;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);
    printf("Enter elements of first list: ");
    struct Node* head1 = createList(n);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);
    printf("Enter elements of second list: ");
    struct Node* head2 = createList(m);

    struct Node *p1 = head1, *p2;

    while (p1) {
        p2 = head2;
        while (p2) {
            if (p1->data == p2->data) {
                printf("%d", p1->data);
                return 0;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    printf("No Intersection");
    return 0;
}