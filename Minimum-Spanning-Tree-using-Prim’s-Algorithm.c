#include <stdio.h>

#define MAX 100
#define INF 1000000000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[MAX], visited[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        visited[i] = 0;
    }

    key[1] = 0;

    int total = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || key[j] < key[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d", total);

    return 0;
}