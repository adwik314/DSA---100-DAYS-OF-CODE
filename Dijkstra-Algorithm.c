#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

struct Node {
    int v;
    int weight;
    struct Node* next;
};

struct Node* adj[MAX];

struct MinHeapNode {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    int* pos;
    struct MinHeapNode** array;
};

struct Node* newNode(int v, int weight) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->weight = weight;
    node->next = NULL;
    return node;
}

void addEdge(int u, int v, int weight) {
    struct Node* node = newNode(v, weight);
    node->next = adj[u];
    adj[u] = node;
}

struct MinHeapNode* newMinHeapNode(int v, int dist) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return heap;
}

void swap(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;

    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        struct MinHeapNode* smallestNode = heap->array[smallest];
        struct MinHeapNode* idxNode = heap->array[idx];

        heap->pos[smallestNode->v] = idx;
        heap->pos[idxNode->v] = smallest;

        swap(&heap->array[smallest], &heap->array[idx]);

        heapify(heap, smallest);
    }
}

int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

struct MinHeapNode* extractMin(struct MinHeap* heap) {
    if (isEmpty(heap)) return NULL;

    struct MinHeapNode* root = heap->array[0];
    struct MinHeapNode* last = heap->array[heap->size - 1];
    heap->array[0] = last;

    heap->pos[root->v] = heap->size - 1;
    heap->pos[last->v] = 0;

    heap->size--;
    heapify(heap, 0);

    return root;
}

void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->v] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->v] = i;
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isInMinHeap(struct MinHeap* heap, int v) {
    return heap->pos[v] < heap->size;
}

void dijkstra(int V, int src) {
    int dist[MAX];

    struct MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        dist[v] = INT_MAX;
        heap->array[v] = newMinHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }

    heap->array[src] = newMinHeapNode(src, 0);
    heap->pos[src] = src;
    dist[src] = 0;
    heap->size = V;

    decreaseKey(heap, src, 0);

    while (!isEmpty(heap)) {
        struct MinHeapNode* minNode = extractMin(heap);
        int u = minNode->v;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->v;

            if (isInMinHeap(heap, v) && dist[u] != INT_MAX &&
                temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(V, src);

    return 0;
}