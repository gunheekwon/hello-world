#include<stdio.h>

int a[1000001];
int b[1000001];

void merge(int min, int mid, int max){
    int i, j, k;
    i= min;
    j= mid+1;
    k= min;

    while(i<=mid&&j<=max)
        if(a[i]<a[j])
            b[k++]= a[i++];
        else
            b[k++]= a[j++];
    while(i<=mid)
        b[k++]= a[i++];
    while(j<=max)
        b[k++]= a[j++];
    for(k= min; k<=max; k++){
        a[k]= b[k];
    }
    return;
}

void merge_sort(int min, int max){
    if(min>=max)
        return;
    int mid= (min+max)/2;
    merge_sort(min, mid);
    merge_sort(mid+1, max);
    merge(min, mid, max);
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    merge_sort(0, n-1);
    for(int i=0; i<n; i++)
        printf("%d\n", a[i]);
}