#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        queue[++rear] = x;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i < rear) printf(" ");
    }

    free(queue);
    return 0;
}