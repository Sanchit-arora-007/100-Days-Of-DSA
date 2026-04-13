#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[MAX * MAX];
int size = 0;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    int i = size++;
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right < size && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest == i) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return root;
}

int isEmpty() {
    return size == 0;
}

void dijkstra(int n, int src) {
    int dist[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    push(src, 0);

    while (!isEmpty()) {
        HeapNode top = pop();
        int u = top.node;
        int d = top.dist;

        if (d > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Shortest distances from source:\n");
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("Node %d: INF\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }
}

int main() {
    int n, e;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    printf("Enter source node: ");
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}