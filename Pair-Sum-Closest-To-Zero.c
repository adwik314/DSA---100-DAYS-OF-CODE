#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int minSum = abs(a[0] + a[1]);
    int x = a[0], y = a[1];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int s = abs(a[i] + a[j]);
            if (s < minSum) {
                minSum = s;
                x = a[i];
                y = a[j];
            }
        }
    }

    printf("Pair closest to zero: %d %d", x, y);

    return 0;
}
