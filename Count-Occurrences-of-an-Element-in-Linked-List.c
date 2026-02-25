#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    int n, x, key, count = 0;
    scanf("%d",&n);

    struct Node *head = NULL, *temp = NULL, *newnode = NULL;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = x;
        newnode->next = NULL;

        if(head==NULL){
            head = newnode;
            temp = newnode;
        }else{
            temp->next = newnode;
            temp = newnode;
        }
    }

    scanf("%d",&key);

    temp = head;
    while(temp!=NULL){
        if(temp->data==key)
            count++;
        temp = temp->next;
    }

    printf("%d",count);

    return 0;
}