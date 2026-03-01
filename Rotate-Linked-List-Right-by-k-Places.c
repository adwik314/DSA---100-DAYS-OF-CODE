#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;
    scanf("%d", &k);

    if (head == NULL || head->next == NULL || k == 0) {
        struct Node* temp = head;
        while (temp) {
            printf("%d", temp->data);
            if (temp->next) printf(" ");
            temp = temp->next;
        }
        return 0;
    }

    int length = 1;
    struct Node* temp = head;
    while (temp->next) {
        temp = temp->next;
        length++;
    }

    tail = temp;
    k = k % length;

    if (k == 0) {
        temp = head;
        while (temp) {
            printf("%d", temp->data);
            if (temp->next) printf(" ");
            temp = temp->next;
        }
        return 0;
    }

    tail->next = head;

    int steps = length - k;
    temp = head;
    for (int i = 1; i < steps; i++)
        temp = temp->next;

    head = temp->next;
    temp->next = NULL;

    temp = head;
    while (temp) {
        printf("%d", temp->data);
        if (temp->next) printf(" ");
        temp = temp->next;
    }

    return 0;
}