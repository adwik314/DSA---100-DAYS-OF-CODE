#include <stdio.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int k;
    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;

    int temp[n];

    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = a[i];
    }

    printf("Rotated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
