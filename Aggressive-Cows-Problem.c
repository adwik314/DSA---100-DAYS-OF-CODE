#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int* pos, int n, int m, int dist) {
    int count = 1;
    int last = pos[0];

    for (int i = 1; i < n; i++) {
        if (pos[i] - last >= dist) {
            count++;
            last = pos[i];
        }
        if (count >= m)
            return 1;
    }

    return 0;
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), cmp);

    int left = 1;
    int right = position[positionSize - 1] - position[0];
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlace(position, positionSize, m, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n, m;
    scanf("%d", &n);

    int position[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    scanf("%d", &m);

    int result = maxDistance(position, n, m);

    printf("%d", result);

    return 0;
}