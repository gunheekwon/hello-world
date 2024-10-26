#include<stdio.h>

int a[310];
int dp[2][310];

int max(int x, int y){
    return x>y?x:y;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }

    // dp[0][i] : i-2칸에서 올라옴
    // dp[1][i] : i-1칸에서 올라옴
    dp[0][1]= a[1];
    dp[0][2]= a[2];
    dp[1][2]= a[1]+a[2];
    for(int i=3; i<=n; i++){
        dp[0][i]= max(dp[0][i-2], dp[1][i-2])+a[i];
        dp[1][i]= dp[0][i-1]+a[i];
    }
    
    printf("%d\n", max(dp[0][n], dp[1][n]));
}