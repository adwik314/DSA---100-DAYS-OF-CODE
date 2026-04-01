#include <stdio.h>

int main() {
    int n, i;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i <= (n - 2) / 2; i++) {
        if (arr[i] > arr[2 * i + 1]) {
            printf("NO");
            return 0;
        }
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2]) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");

    return 0;
}