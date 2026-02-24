#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

struct Node* append(struct Node* head, int x) {
    struct Node* n = createNode(x);
    if (!head) return n;
    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    return head;
}

struct Node* deleteFirst(struct Node* head, int key) {
    if (!head) return head;
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* prev = head;
    struct Node* curr = head->next;
    while (curr) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

void printList(struct Node* head) {
    struct Node* t = head;
    while (t) {
        printf("%d", t->data);
        if (t->next) printf(" ");
        t = t->next;
    }
}

int main() {
    int n, x, key;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = append(head, x);
    }
    scanf("%d", &key);

    head = deleteFirst(head, key);
    printList(head);

    return 0;
}
