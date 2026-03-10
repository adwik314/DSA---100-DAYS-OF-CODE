#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void init(Deque *dq){
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

int empty(Deque *dq){
    return dq->size == 0;
}

int sizeDeque(Deque *dq){
    return dq->size;
}

void push_front(Deque *dq, int val){
    if(dq->size == MAX) return;
    if(dq->front == -1){
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = val;
    dq->size++;
}

void push_back(Deque *dq, int val){
    if(dq->size == MAX) return;
    if(dq->rear == -1){
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = val;
    dq->size++;
}

int pop_front(Deque *dq){
    if(empty(dq)) return -1;
    int val = dq->arr[dq->front];
    if(dq->front == dq->rear){
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
    dq->size--;
    return val;
}

int pop_back(Deque *dq){
    if(empty(dq)) return -1;
    int val = dq->arr[dq->rear];
    if(dq->front == dq->rear){
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
    dq->size--;
    return val;
}

int front(Deque *dq){
    if(empty(dq)) return -1;
    return dq->arr[dq->front];
}

int back(Deque *dq){
    if(empty(dq)) return -1;
    return dq->arr[dq->rear];
}

void clearDeque(Deque *dq){
    dq->front = dq->rear = -1;
    dq->size = 0;
}

void reverseDeque(Deque *dq){
    if(empty(dq)) return;
    int temp[MAX];
    int i, idx = dq->front;
    for(i = 0; i < dq->size; i++){
        temp[i] = dq->arr[idx];
        idx = (idx + 1) % MAX;
    }
    for(i = 0; i < dq->size; i++){
        dq->arr[(dq->front + i) % MAX] = temp[dq->size - i - 1];
    }
}

void sortDeque(Deque *dq){
    if(empty(dq)) return;
    int temp[MAX];
    int i, j, idx = dq->front;
    for(i = 0; i < dq->size; i++){
        temp[i] = dq->arr[idx];
        idx = (idx + 1) % MAX;
    }
    for(i = 0; i < dq->size - 1; i++){
        for(j = i + 1; j < dq->size; j++){
            if(temp[i] > temp[j]){
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    for(i = 0; i < dq->size; i++){
        dq->arr[(dq->front + i) % MAX] = temp[i];
    }
}

int main(){
    Deque dq;
    init(&dq);

    int n, x;
    char op[20];
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%s", op);

        if(strcmp(op,"push_front")==0){
            scanf("%d",&x);
            push_front(&dq,x);
        }
        else if(strcmp(op,"push_back")==0){
            scanf("%d",&x);
            push_back(&dq,x);
        }
        else if(strcmp(op,"pop_front")==0){
            printf("%d\n",pop_front(&dq));
        }
        else if(strcmp(op,"pop_back")==0){
            printf("%d\n",pop_back(&dq));
        }
        else if(strcmp(op,"front")==0){
            printf("%d\n",front(&dq));
        }
        else if(strcmp(op,"back")==0){
            printf("%d\n",back(&dq));
        }
        else if(strcmp(op,"empty")==0){
            printf("%d\n",empty(&dq));
        }
        else if(strcmp(op,"size")==0){
            printf("%d\n",sizeDeque(&dq));
        }
        else if(strcmp(op,"clear")==0){
            clearDeque(&dq);
        }
        else if(strcmp(op,"reverse")==0){
            reverseDeque(&dq);
        }
        else if(strcmp(op,"sort")==0){
            sortDeque(&dq);
        }
    }

    return 0;
}