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

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int intersectPoint(struct Node* head1, struct Node* head2) {
    struct Node* p1 = head1;
    struct Node* p2 = head2;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }

    if (p1 == NULL)
        return -1;

    return p1->data;
}

int main() {
    int n1, n2, i;

    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        int val;
        scanf("%d", &val);
        append(&head1, val);
    }

    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        int val;
        scanf("%d", &val);
        append(&head2, val);
    }

    int result = intersectPoint(head1, head2);

    if (result == -1)
        printf("No Intersection\n");
    else
        printf("%d\n", result);

    return 0;
}