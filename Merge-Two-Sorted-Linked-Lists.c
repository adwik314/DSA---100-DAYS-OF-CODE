#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create(int n){
    struct node *head=NULL,*temp=NULL,*newnode;
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL) head=temp=newnode;
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

struct node* merge(struct node* a, struct node* b){
    struct node dummy;
    struct node* tail=&dummy;
    dummy.next=NULL;

    while(a && b){
        if(a->data <= b->data){
            tail->next=a;
            a=a->next;
        } else{
            tail->next=b;
            b=b->next;
        }
        tail=tail->next;
    }

    if(a) tail->next=a;
    else tail->next=b;

    return dummy.next;
}

void print(struct node* head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    int n,m;

    printf("Enter size of first list: ");
    scanf("%d",&n);
    struct node* l1=create(n);

    printf("Enter size of second list: ");
    scanf("%d",&m);
    struct node* l2=create(m);

    struct node* result=merge(l1,l2);

    printf("Merged list:\n");
    print(result);

    return 0;
}