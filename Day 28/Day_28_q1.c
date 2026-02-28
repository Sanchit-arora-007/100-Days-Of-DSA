#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) return 0;

    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    printf("Enter %d values: ", n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp->next = head;

    struct node* curr = head;
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != head);

    return 0;
}