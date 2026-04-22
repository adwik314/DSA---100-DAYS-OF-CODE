#include <stdio.h>

#define MAX 1000

int main() {
    int arr[MAX], n = 0;

    while (scanf("%d", &arr[n]) == 1) {
        n++;
    }

    int prefix[MAX];
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        if (prefix[i] == 0) {
            if (i + 1 > maxLen)
                maxLen = i + 1;
        }

        for (int j = i + 1; j < n; j++) {
            if (prefix[j] == prefix[i]) {
                if (j - i > maxLen)
                    maxLen = j - i;
            }
        }
    }

    printf("%d", maxLen);

    return 0;
}