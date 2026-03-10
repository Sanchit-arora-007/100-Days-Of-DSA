#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == 0 && rear == MAX-1) || (front == rear + 1);
}

void push_front(int value) {
    if(isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else if(front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = value;
}

void push_back(int value) {
    if(isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else if(rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
}

void pop_front() {
    if(isEmpty()) {
        printf("-1\n");
        return;
    }

    int val = deque[front];
    printf("%d\n", val);

    if(front == rear) {
        front = rear = -1;
    }
    else if(front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

void pop_back() {
    if(isEmpty()) {
        printf("-1\n");
        return;
    }

    int val = deque[rear];
    printf("%d\n", val);

    if(front == rear) {
        front = rear = -1;
    }
    else if(rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

void getFront() {
    if(isEmpty())
        printf("-1\n");
    else
        printf("%d\n", deque[front]);
}

void getBack() {
    if(isEmpty())
        printf("-1\n");
    else
        printf("%d\n", deque[rear]);
}

void getSize() {
    if(isEmpty()) {
        printf("0\n");
        return;
    }

    if(rear >= front)
        printf("%d\n", rear - front + 1);
    else
        printf("%d\n", MAX - front + rear + 1);
}

void clearDeque() {
    front = rear = -1;
}

void display() {
    if(isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;

    while(1) {
        printf("%d ", deque[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n, value;
    char op[20];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter operation: ");
        scanf("%s", op);

        if(strcmp(op, "push_front") == 0) {
            printf("Enter value: ");
            scanf("%d", &value);
            push_front(value);
        }
        else if(strcmp(op, "push_back") == 0) {
            printf("Enter value: ");
            scanf("%d", &value);
            push_back(value);
        }
        else if(strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if(strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if(strcmp(op, "front") == 0) {
            getFront();
        }
        else if(strcmp(op, "back") == 0) {
            getBack();
        }
        else if(strcmp(op, "size") == 0) {
            getSize();
        }
        else if(strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        }
        else if(strcmp(op, "clear") == 0) {
            clearDeque();
        }
    }

    printf("Final Deque: ");
    display();

    return 0;
}