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

Node* LCA(Node* root,int a,int b){
    if(root==NULL) return NULL;
    if(root->data==a || root->data==b) return root;

    Node* left=LCA(root->left,a,b);
    Node* right=LCA(root->right,a,b);

    if(left && right) return root;
    return left?left:right;
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    Node* nodes[n];

    for(int i=0;i<n;i++){
        if(arr[i]==-1)
            nodes[i]=NULL;
        else
            nodes[i]=createNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i]!=NULL){
            int l=2*i+1;
            int r=2*i+2;

            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }

    int a,b;
    scanf("%d %d",&a,&b);

    Node* root=nodes[0];
    Node* ans=LCA(root,a,b);

    printf("%d",ans->data);

    return 0;
}