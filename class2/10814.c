#include<stdio.h>

char name[100010][101];
int age[100010];
int idx[100010];

void merge(int min, int mid, int max){
    int i, j, k;
    int tmp[max+1];
    i= min;
    j= mid+1;
    k= min;
    while(i<=mid&&j<=max){
        if(age[idx[i]]<=age[idx[j]])
            tmp[k++]= idx[i++];
        else
            tmp[k++]= idx[j++];
    }
    while(i<=mid){
        tmp[k++]= idx[i++];
    }
    while(j<=max){
        tmp[k++]= idx[j++];
    }
    for(k= min; k<=max; k++){
        idx[k]= tmp[k];
    }
    return;
}

void merge_sort(int min, int max){
    if(min>=max) return;
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
        scanf("%d %s", &age[i], name[i]);
        idx[i]= i;
    }

    merge_sort(0, n-1);
    for(int i=0; i<n; i++){
        printf("%d %s\n", age[idx[i]], name[idx[i]]);
    }
    return 0;
}