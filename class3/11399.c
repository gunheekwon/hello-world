#include<stdio.h>

int a[1010];

void merge(int min, int mid, int max){
    int b[1010];
    int idx1, idx2, idx3;
    idx1= min;
    idx2= mid+1;
    idx3= min;
    while(idx1<=mid&&idx2<=max){
        if(a[idx1]<=a[idx2])
            b[idx3++]= a[idx1++];
        else b[idx3++]= a[idx2++];
    }
    while(idx1<=mid)
        b[idx3++]= a[idx1++];
    while(idx2<=max)
        b[idx3++]= a[idx2++];
    for(idx3= min; idx3<=max; idx3++)
        a[idx3]= b[idx3];
    return;
}

void mergesort(int min, int max){
    if(min>=max) return;
    int mid= (min+max)/2;
    mergesort(min, mid);
    mergesort(mid+1, max);
    merge(min, mid, max);
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    mergesort(0, n-1);
    // for(int i=0; i<n; i++){
    //     printf("%d\t", a[i]);
    // }
    // puts("");
    int result= a[0];
    for(int i=1; i<n; i++){
        a[i]+= a[i-1];
        result+= a[i];
        // printf("%d\t", result);
    }
    // puts("");
    printf("%d\n", result);
}