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

Node* LCA(Node* root,int a,int b){
    if(root==NULL) return NULL;

    if(a < root->data && b < root->data)
        return LCA(root->left,a,b);
    else if(a > root->data && b > root->data)
        return LCA(root->right,a,b);
    else
        return root;
}

int main(){
    int n,x,a,b;
    scanf("%d",&n);

    Node* root=NULL;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        root=insert(root,x);
    }

    scanf("%d %d",&a,&b);

    Node* ans=LCA(root,a,b);
    printf("%d",ans->data);

    return 0;
}