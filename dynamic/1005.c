#include<stdio.h>

void f(){
    int n, k, w;
    int v[1010];
    int cnt[1010];
    int queue_top, queue_cnt;
    int queue[1010];
    int dp[1010];
    int g[1010][1010];

    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    for(int i=0; i<k; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a-1][b-1]= v[a-1];
        cnt[b-1]++;
    }
    scanf("%d", &w);

    for(int i=0; i<n; i++){
        printf("%d ", cnt[i]);
    }
    puts("");

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", g[i][j]);
        }
        puts("");
    }

    queue_cnt= 0;
    queue_top= 0;
    while(queue_cnt<n){
        for(int i=0; i<n; i++){
            if(cnt[i]==0){
                printf("push %d\n", i);
                queue[queue_top++]= i;
                cnt[i]=-1;
            }
        }
        // printf("%d %d\n", queue_cnt, queue_top);
        for(; queue_cnt<=queue_top; queue_cnt++){
            int a= queue[queue_cnt];
            for(int b=0; b<n; b++){
                if(g[a][b]){
                    if(dp[b]<dp[a]+g[a][b])
                        dp[b]= dp[a]+g[a][b];
                    cnt[b]--;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            printf("%d ", dp[i]);
        }
        puts("");
    }
    

    printf("%d\n", dp[w-1]+v[w-1]);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        f();
    }
}