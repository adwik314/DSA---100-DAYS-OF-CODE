#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);

    int *q = (int*)malloc(sizeof(int)*n);
    int front = 0, rear = -1;

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        rear = (rear + 1) % n;
        q[rear] = x;
    }

    int m;
    scanf("%d",&m);

    for(int i=0;i<m;i++){
        front = (front + 1) % n;
    }

    int count = n - m;
    for(int i=0;i<count;i++){
        int idx = (front + i) % n;
        printf("%d", q[idx]);
        if(i < count-1) printf(" ");
    }

    free(q);
    return 0;
}