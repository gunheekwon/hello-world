#include<stdio.h>

int n;
int a[1000010];
int b[1000010];
int c[1000010];

void mergesort(int s, int e){
    if(s==e) return;
    int m = (s+e)/2;
    
    mergesort(s, m);
    mergesort(m+1, e);

    int i, j, k;
    i= s, j= m+1, k= s;
    while(i<=m&&j<=e){
        if(a[b[i]]<=a[b[j]])
            c[k++]= b[i++];
        else c[k++]= b[j++];
    }
    while(i<=m) c[k++]= b[i++];
    while(j<=e) c[k++]= b[j++];

    for(int i=s; i<=e; i++)
        b[i]= c[i];

    // for(int i=0; i<n; i++){
    //     printf("%d ", a[b[i]]);
    // }
    // puts("");

    return;
}

int find(int x, int s, int e){
    if(s==e&&x==a[b[s]]) return s;
    int m= (s+e)/2;
    if(x<=a[b[m]]) return find(x, s, m);
    else return find(x, m+1, e);
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        b[i]= i;
    }
    mergesort(0, n-1);
    
    // for(int i=0; i<n; i++){
    //     printf("%d ", i);
    // }
    // puts("");
    // for(int i=0; i<n; i++){
    //     printf("%d ", b[i]);
    // }
    // puts("");

    // for(int i=0; i<n; i++){
    //     printf("%d ", a[b[i]]);
    // }
    // puts("");

    
    int tmp=0;
    for(int i=0; i<n; i++){
        if(i>0&&a[b[i]]==a[b[i-1]]){
            tmp--;
        }
        c[b[i]]= tmp++;
    }
    for(int i=0; i<n; i++){
        printf("%d ", c[i]);
    }
    puts("");
}