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

void levelOrder(Node* root){
    if(root==NULL) return;

    Node* queue[1000];
    int front=0,rear=0;

    queue[rear++]=root;

    while(front<rear){
        Node* temp=queue[front++];
        printf("%d ",temp->data);

        if(temp->left!=NULL)
            queue[rear++]=temp->left;

        if(temp->right!=NULL)
            queue[rear++]=temp->right;
    }
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(n==0 || arr[0]==-1) return 0;

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
    levelOrder(root);

    return 0;
}