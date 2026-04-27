#include <stdio.h>
#include <limits.h>

#define MAX 1000

int n, m;
int adj[MAX][MAX];
int visited[MAX];
int minEdge[MAX];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = INT_MAX;
        }
        visited[i] = 0;
        minEdge[i] = INT_MAX;
    }

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    minEdge[1] = 0;
    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        int min = INT_MAX, node = -1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && minEdge[j] < min) {
                min = minEdge[j];
                node = j;
            }
        }

        visited[node] = 1;
        totalWeight += min;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && adj[node][j] < minEdge[j]) {
                minEdge[j] = adj[node][j];
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}