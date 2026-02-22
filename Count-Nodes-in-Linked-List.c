#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    struct node *head=NULL,*temp=NULL,*newnode;

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL){
            head=temp=newnode;
        } else {
            temp->next=newnode;
            temp=newnode;
        }
    }

    int count=0;
    temp=head;

    printf("Linked list:\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        count++;
        temp=temp->next;
    }

    printf("\nCount of nodes: %d",count);
    return 0;
}