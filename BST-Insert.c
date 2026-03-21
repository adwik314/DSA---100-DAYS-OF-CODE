#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

Node* createNode(int val){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}

Node* insert(Node* root,int val){
    if(root==NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left,val);
    else
        root->right = insert(root->right,val);

    return root;
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
    int n,x;
    scanf("%d",&n);

    Node* root=NULL;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        root = insert(root,x);
    }

    inorder(root);

    return 0;
}