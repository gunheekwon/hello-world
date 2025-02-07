#include<stdio.h>
// gcc -o 1927 1927.c
// ./1927
int a[100010];
int size;

int min(int x, int y){
    return x<y?x:y;
}

void print_heap(){
    for(int i=1; i<=size; i++)
        printf("%d ", a[i]);
    puts("");
    return;
}

void push(int k){
    a[++size]= k;
    int idx= size;
    while(idx/2&&a[idx]<a[idx/2]){
        int tmp= a[idx];
        a[idx]= a[idx/2];
        a[idx/2]= tmp;
        idx/=2;
    }
    while(idx*2+1<=size&&a[idx]>min(a[idx*2], a[idx*2+1])){
        if(a[idx*2]<a[idx*2+1]){
            int tmp= a[idx];
            a[idx]= a[idx*2];
            a[idx*2]= tmp;
            idx*=2;
        }else{
            int tmp= a[idx];
            a[idx]= a[idx*2+1];
            a[idx*2+1]= tmp;
            idx=2*idx+1;
        }
    }
    if(idx*2<=size&&a[idx]>a[idx*2]){
        int tmp= a[idx];
        a[idx]= a[idx*2];
        a[idx*2]= tmp;
    }
    // print_heap();
}

void pop(){
    if(!size){
        puts("0");
        return;
    }
    printf("%d\n", a[1]);
    a[1]= a[size];
    a[size--]= 0;
    int idx= 1;
    while(idx*2+1<=size&&a[idx]>min(a[idx*2], a[idx*2+1])){
        if(a[idx*2]<a[idx*2+1]){
            int tmp= a[idx];
            a[idx]= a[idx*2];
            a[idx*2]= tmp;
            idx*=2;
        }else{
            int tmp= a[idx];
            a[idx]= a[idx*2+1];
            a[idx*2+1]= tmp;
            idx=2*idx+1;
        }
    }
    if(idx*2<=size&&a[idx]>a[idx*2]){
        int tmp= a[idx];
        a[idx]= a[idx*2];
        a[idx*2]= tmp;
    }
    // print_heap();
}

int main(){
    int n;
    size= 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int k;
        scanf("%d", &k);
        if(k) push(k);
        else pop();
    }
}