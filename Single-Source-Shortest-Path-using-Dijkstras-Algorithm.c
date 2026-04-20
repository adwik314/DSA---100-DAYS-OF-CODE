#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAX];

struct HeapNode {
    int v, dist;
};

struct MinHeap {
    int size;
    int pos[MAX];
    struct HeapNode* arr[MAX];
};

struct Node* newNode(int v, int w) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->v = v;
    temp->w = w;
    temp->next = NULL;
    return temp;
}

void addEdge(int u, int v, int w) {
    struct Node* temp = newNode(v, w);
    temp->next = adj[u];
    adj[u] = temp;

    temp = newNode(u, w);
    temp->next = adj[v];
    adj[v] = temp;
}

void swap(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int l = 2*idx + 1;
    int r = 2*idx + 2;

    if (l < heap->size && heap->arr[l]->dist < heap->arr[smallest]->dist)
        smallest = l;

    if (r < heap->size && heap->arr[r]->dist < heap->arr[smallest]->dist)
        smallest = r;

    if (smallest != idx) {
        heap->pos[heap->arr[smallest]->v] = idx;
        heap->pos[heap->arr[idx]->v] = smallest;
        swap(&heap->arr[smallest], &heap->arr[idx]);
        heapify(heap, smallest);
    }
}

struct HeapNode* extractMin(struct MinHeap* heap) {
    if (heap->size == 0) return NULL;

    struct HeapNode* root = heap->arr[0];
    struct HeapNode* last = heap->arr[heap->size - 1];

    heap->arr[0] = last;
    heap->pos[last->v] = 0;
    heap->size--;

    heapify(heap, 0);
    return root;
}

void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->arr[i]->dist = dist;

    while (i && heap->arr[i]->dist < heap->arr[(i-1)/2]->dist) {
        heap->pos[heap->arr[i]->v] = (i-1)/2;
        heap->pos[heap->arr[(i-1)/2]->v] = i;
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int isInHeap(struct MinHeap* heap, int v) {
    return heap->pos[v] < heap->size;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    int dist[MAX];
    struct MinHeap heap;
    heap.size = n;

    for (int i = 1; i <= n; i++) {
        heap.arr[i-1] = (struct HeapNode*)malloc(sizeof(struct HeapNode));
        heap.arr[i-1]->v = i;
        heap.arr[i-1]->dist = INT_MAX;
        heap.pos[i] = i-1;
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    heap.arr[src-1]->dist = 0;
    decreaseKey(&heap, src, 0);

    while (heap.size > 0) {
        struct HeapNode* min = extractMin(&heap);
        int u = min->v;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->v;

            if (isInHeap(&heap, v) && dist[u] != INT_MAX &&
                dist[u] + temp->w < dist[v]) {
                dist[v] = dist[u] + temp->w;
                decreaseKey(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}