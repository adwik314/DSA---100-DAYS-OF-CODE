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

int isMirror(Node* a, Node* b){
    if(a==NULL && b==NULL) return 1;
    if(a==NULL || b==NULL) return 0;
    if(a->data != b->data) return 0;

    return isMirror(a->left,b->right) && isMirror(a->right,b->left);
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(n==0 || arr[0]==-1){
        printf("YES");
        return 0;
    }

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

    Node* root=nodes[0];

    if(isMirror(root->left,root->right))
        printf("YES");
    else
        printf("NO");

    return 0;
}