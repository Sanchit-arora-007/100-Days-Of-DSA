#include <stdio.h>

int stack[100];
int top = -1;

void push(int value){
    top++;
    stack[top] = value;
}

void pop(){
    if(top == -1){
        return;
    }
    top--;
}

int main(){
    int n, m, value;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        push(value);
    }

    printf("Enter number of pops: ");
    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        pop();
    }

    printf("Remaining stack elements (top to bottom):\n");
    for(int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }

    return 0;
}