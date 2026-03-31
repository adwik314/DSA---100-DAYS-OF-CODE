#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int postIndex;

int findIndex(int inorder[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int start, int end) {
    if (start > end)
        return NULL;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = postorder[postIndex];
    node->left = NULL;
    node->right = NULL;

    postIndex--;

    if (start == end)
        return node;

    int index = findIndex(inorder, start, end, node->data);

    node->right = buildTree(inorder, postorder, index + 1, end);
    node->left = buildTree(inorder, postorder, start, index - 1);

    return node;
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n, i;

    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    preorder(root);

    return 0;
}