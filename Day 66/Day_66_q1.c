#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int graph[MAX][MAX];
int graphColSize[MAX];
int visited[MAX];

int dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];

        if (visited[neighbor] == 1)
            return 1;

        if (visited[neighbor] == 0) {
            if (dfs(neighbor))
                return 1;
        }
    }

    visited[node] = 2;
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        graphColSize[i] = 0;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][graphColSize[u]++] = v;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}