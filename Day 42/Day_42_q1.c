#include <stdio.h>
#include <stdlib.h>

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

int dequeue(){
    if(front==NULL)
        return -1;

    struct Node* temp=front;
    int val=temp->data;
    front=front->next;

    if(front==NULL)
        rear=NULL;

    free(temp);
    return val;
}

int main(){
    int N;
    scanf("%d",&N);

    int stack[N];
    int top=-1;

    for(int i=0;i<N;i++){
        int x;
        scanf("%d",&x);
        enqueue(x);
    }

    while(front!=NULL)
        stack[++top]=dequeue();

    for(int i=top;i>=0;i--)
        enqueue(stack[i]);

    struct Node* temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}