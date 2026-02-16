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

    for (int i = 0; i < n; i++) {
        int count = 1;
        int visited = 0;

        for (int k = 0; k < i; k++) {
            if (a[i] == a[k]) {
                visited = 1;
                break;
            }
        }

        if (visited)
            continue;

        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
            }
        }

        printf("%d:%d ", a[i], count);
    }

    return 0;
}
