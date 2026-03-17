#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *front=NULL,*rear=NULL;

void enqueue(int x){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;

    if(rear==NULL){
        front=rear=newNode;
        return;
    }

    rear->next=newNode;
    rear=newNode;
}

void dequeue(){
    if(front==NULL){
        printf("-1\n");
        return;
    }

    struct Node* temp=front;
    printf("%d\n",front->data);
    front=front->next;

    if(front==NULL)
        rear=NULL;

    free(temp);
}

int main(){
    int N;

    printf("Enter number of operations: ");
    scanf("%d",&N);

    while(N--){
        char op[10];

        printf("Enter operation (enqueue/dequeue): ");
        scanf("%s",op);

        if(strcmp(op,"enqueue")==0){
            int x;
            printf("Enter value: ");
            scanf("%d",&x);
            enqueue(x);
        }
        else if(strcmp(op,"dequeue")==0){
            dequeue();
        }
    }

    return 0;
}