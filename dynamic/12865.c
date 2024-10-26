#include<stdio.h>

int w[101];
int v[101];
int dp[100001];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d %d", &w[i], &v[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=k-w[i]; j>=0; j--){            
            if(dp[w[i]+j]<dp[j]+v[i]){
                dp[w[i]+j]= dp[j]+v[i];
            }
        }
    }
    int max= 0;
    for(int i=0; i<=k; i++){
        if(dp[i]>max)
            max= dp[i];
    }
    
    printf("%d\n", max);
}