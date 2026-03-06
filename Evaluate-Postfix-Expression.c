#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** top,int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=*top;
    *top=newNode;
}

int pop(struct Node** top){
    struct Node* temp=*top;
    int val=temp->data;
    *top=temp->next;
    free(temp);
    return val;
}

int main(){
    char line[1000];
    fgets(line,1000,stdin);

    struct Node* top=NULL;
    char* token=strtok(line," ");

    while(token){
        if(isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))){
            push(&top,atoi(token));
        }else{
            int b=pop(&top);
            int a=pop(&top);
            int res;

            if(token[0]=='+') res=a+b;
            else if(token[0]=='-') res=a-b;
            else if(token[0]=='*') res=a*b;
            else if(token[0]=='/') res=a/b;

            push(&top,res);
        }
        token=strtok(NULL," ");
    }

    printf("%d",pop(&top));
    return 0;
}