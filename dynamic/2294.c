#include<stdio.h>

int coin[110];
int dp[10010];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &coin[i]);
    }

    for(int j=0; j<=k; j++)
        dp[j]= -1;
    
    dp[0]= 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(dp[j]!=-1&&j+coin[i]<=k){
                if(dp[j+coin[i]]==-1){
                    dp[j+coin[i]]= dp[j]+1;
                }else if(dp[j+coin[i]]>dp[j]+1)
                    dp[j+coin[i]]= dp[j]+1;
            }    
        }
    }

    printf("%d\n", dp[k]);
}