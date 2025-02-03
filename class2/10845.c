#include<stdio.h>
#include<stdlib.h>
#define null NULL;

typedef struct node{
    int data;
    struct node* next;
} Node;

typedef struct queue{
    int size;
    Node* head;
    Node* tail;
} Queue;

Queue* init_queue(){
    Queue* q= (Queue*)malloc(sizeof(Queue));
    q->size= 0;
    q->head= null;
    q->tail= null;
    return q;
}

void push(Queue* q, int k){
    Node* newone= (Node*)malloc(sizeof(Node));
    newone->data= k;
    newone->next= null;

    if(!q->size)
        q->head= newone;
    else
        q->tail->next= newone;
    q->size++;
    q->tail= newone;
}

int pop(Queue* q){
    if(!q->size)
        return -1;

    int k= q->head->data;
    Node* delone= q->head;
    q->head= q->head->next;
    q->size--;
    free(delone);
    return k;
}

int size(Queue* q){
    return q->size;
}

int empty(Queue* q){
    return !q->size;
}

int front(Queue* q){
    if(!q->size)
        return -1;
    return q->head->data;
}

int back(Queue* q){
    if(!q->size)
        return -1;
    return q->tail->data;
}

void free_queue(Queue* q){
    while(q->size)
        pop(q);
    free(q);
    return;
}

int main(){
    Queue* q= init_queue();
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        char a[10];
        scanf("%s", a);
        if(a[1]=='u'){
            int b;
            scanf("%d", &b);
            push(q, b);
        }else{
            switch(a[0]){
                case 'p': // pop
                    printf("%d\n", pop(q));
                    break;
                case 's': //size
                    printf("%d\n", size(q));
                    break;
                case 'e': //empty
                    printf("%d\n", empty(q));
                    break;
                case 'f': //front
                    printf("%d\n", front(q));
                    break;
                case 'b': //back
                    printf("%d\n", back(q));
                    break;
                default:
                    puts("error!");
            }
        }
    }
}