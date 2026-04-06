#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int parent, int** adj, int* adjSize, int* visited) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, adjSize, visited))
                return 1;
        } else if (neighbor != parent) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int** edges = (int**)malloc(E * sizeof(int*));
    for (int i = 0; i < E; i++) {
        edges[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int* adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < E; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    int** adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int* visited = (int*)calloc(V, sizeof(int));

    int hasCycle = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, adjSize, visited)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}