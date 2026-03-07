#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int queue[n];
    int front = -1, rear = -1;

    printf("Enter %d elements: ", n);

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = x;
    }

    printf("Queue elements: ");
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    return 0;
}