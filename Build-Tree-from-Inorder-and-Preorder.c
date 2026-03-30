#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

Node* createNode(int val){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int findIndex(int inorder[], int start, int end, int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val) return i;
    }
    return -1;
}

Node* build(int preorder[], int inorder[], int start, int end, int *preIndex){
    if(start > end) return NULL;

    Node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if(start == end) return root;

    int idx = findIndex(inorder, start, end, root->data);

    root->left = build(preorder, inorder, start, idx-1, preIndex);
    root->right = build(preorder, inorder, idx+1, end, preIndex);

    return root;
}

void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    int n;
    scanf("%d",&n);

    int preorder[n], inorder[n];

    for(int i=0;i<n;i++)
        scanf("%d",&preorder[i]);

    for(int i=0;i<n;i++)
        scanf("%d",&inorder[i]);

    int preIndex = 0;

    Node* root = build(preorder, inorder, 0, n-1, &preIndex);

    postorder(root);

    return 0;
}