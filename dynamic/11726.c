#include<stdio.h>

int a[1010];

int main(){
    int n;
    scanf("%d", &n);

    a[1]= 1;
    a[2]= 2;
    for(int i=3; i<=n; i++){
        a[i]= a[i-1]+a[i-2];
        a[i]%=10007;
    }

    printf("%d\n", a[n]);
}