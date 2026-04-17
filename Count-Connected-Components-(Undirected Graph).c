#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int** adj, int* adjSize, int* visited) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, adj, adjSize, visited);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** edges = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        edges[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int* adjSize = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, adjSize, visited);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}