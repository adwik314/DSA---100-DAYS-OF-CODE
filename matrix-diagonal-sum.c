#include <stdio.h>

int main() {
    int m, n;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int a[m][n];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int sum = 0;
    int limit = m < n ? m : n;

    for (int i = 0; i < limit; i++) {
        sum += a[i][i];
    }

    printf("Sum of primary diagonal = %d", sum);

    return 0;
}
