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

    if(!q->size) q->head= newone;
    else q->tail->next= newone;
    q->size++;
    q->tail= newone;
    return;
}

int pop(Queue* q){
    if(!q->size)
        return -1;
    Node* delone= q->head;
    int k= delone->data;
    q->head= q->head->next;
    q->size--;
    free(delone);
    return k;
}

void free_queue(Queue* q){
    while(q->size)
        pop(q);
    free(q);
    return;
}

int main(){
    Queue* q= init_queue();
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        push(q, i);
    }
    printf("<");
    for(int i=1; q->size>1; i++){
        int tmp= pop(q);
        if(i%k) push(q, tmp);
        else printf("%d, ", tmp);
    }
    printf("%d>\n", q->head->data);
    free_queue(q);
}