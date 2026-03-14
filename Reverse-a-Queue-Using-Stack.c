#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    int queue[MAX], stack[MAX];
    int top = -1;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
        stack[++top] = queue[i];
    }

    for(int i = 0; i < n; i++) {
        queue[i] = stack[top--];
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}