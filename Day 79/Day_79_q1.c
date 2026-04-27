#include <stdio.h>
#include <limits.h>

#define MAX 1000

int n, m;
int adj[MAX][MAX];
int dist[MAX];
int visited[MAX];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = INT_MAX;
        }
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int source;
    scanf("%d", &source);

    dist[source] = 0;

    for (int i = 1; i <= n; i++) {
        int min = INT_MAX, node = -1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                node = j;
            }
        }

        visited[node] = 1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && adj[node][j] != INT_MAX) {
                if (dist[node] + adj[node][j] < dist[j]) {
                    dist[j] = dist[node] + adj[node][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}