#include <stdio.h>

int stack[100];
int top = -1;

void push(int value){
    top++;
    stack[top] = value;
}

void pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top]);
    top--;
}

void display(){
    if(top == -1){
        return;
    }
    for(int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main(){
    int n, op, value;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter operation: ");
        scanf("%d", &op);

        if(op == 1){
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
        }
        else if(op == 2){
            pop();
        }
        else if(op == 3){
            display();
        }
    }

    return 0;
}