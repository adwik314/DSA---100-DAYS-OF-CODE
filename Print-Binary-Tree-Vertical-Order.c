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

void vertical(Node* root,int hd,int arr[200][200],int count[],int *min,int *max){
    if(root==NULL) return;

    int index=hd+100;
    arr[index][count[index]++]=root->data;

    if(hd<*min) *min=hd;
    if(hd>*max) *max=hd;

    vertical(root->left,hd-1,arr,count,min,max);
    vertical(root->right,hd+1,arr,count,min,max);
}

int main(){
    int n;
    scanf("%d",&n);

    int arrInput[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arrInput[i]);

    Node* nodes[n];

    for(int i=0;i<n;i++){
        if(arrInput[i]==-1)
            nodes[i]=NULL;
        else
            nodes[i]=createNode(arrInput[i]);
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

    int arr[200][200]={0};
    int count[200]={0};
    int min=0,max=0;

    vertical(root,0,arr,count,&min,&max);

    for(int i=min;i<=max;i++){
        int index=i+100;
        for(int j=0;j<count[index];j++)
            printf("%d ",arr[index][j]);
        printf("\n");
    }

    return 0;
}