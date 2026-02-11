#include <stdio.h>

int main() {
    int m, n;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int a[100][100], b[100][100];

    printf("Enter first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter second matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("Resultant matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
