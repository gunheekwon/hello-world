#include<stdio.h>

int heap[1000010];

void swap(int x, int y){
    int tmp= heap[x];
    heap[x]= heap[y];
    heap[y]= tmp;
    return;
}

void sort(int x){
    if(x==0) return;

    if(child>parent){
        swap(x/2, x);
        sort(x/2);
    }
}

void add_heap(int x, int k){
    heap[x]= k;
    sort(x);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int k;
        scanf("%d", &k);
        add_heap(i, k);
    }

    int ans= 0;
    for(int i= n-1; i>0; i++){
        int tmp= heap[i-1] + heap[i];
        ans += tmp;
        heap[i]= 0;
        add_heap(i-1, tmp);
    }

    printf("%d\n", ans);
}