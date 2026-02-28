#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (tail != NULL)
        tail->next = head;

    if (head != NULL) {
        struct Node* temp = head;
        do {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp != head)
                printf(" ");
        } while (temp != head);
    }

    return 0;
}