#include <stdio.h>

int main() {
    int n;
    printf("Enter size of matrix: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int identity = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j && a[i][j] != 1) || (i != j && a[i][j] != 0)) {
                identity = 0;
                break;
            }
        }
        if (!identity) break;
    }

    if (identity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
