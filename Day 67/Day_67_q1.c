#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void dfs(int node, int visited[], int** adj, int adjSize[]) {
    visited[node] = 1;

    for(int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if(!visited[next]) {
            dfs(next, visited, adj, adjSize);
        }
    }

    push(node);
}

void topoSort(int V, int** adj, int adjSize[]) {
    int visited[V];

    for(int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i, visited, adj, adjSize);
        }
    }

    printf("Topological Order:\n");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int V = 6;

    int** adj = (int**)malloc(V * sizeof(int*));
    int adjSize[V];

    for(int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int));
        adjSize[i] = 0;
    }

    adj[5][adjSize[5]++] = 2;
    adj[5][adjSize[5]++] = 0;
    adj[4][adjSize[4]++] = 0;
    adj[4][adjSize[4]++] = 1;
    adj[2][adjSize[2]++] = 3;
    adj[3][adjSize[3]++] = 1;

    topoSort(V, adj, adjSize);

    return 0;
}