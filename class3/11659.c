#include<stdio.h>

int a[100010];
int b[100010];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        b[i]= a[i]+b[i-1];
    }
    for(int i=0; i<m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", b[y]-b[x-1]);
    }
}