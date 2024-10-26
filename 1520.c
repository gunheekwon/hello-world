#include<stdio.h>
#include<stdlib.h>

int m, n;
int a[510][510];
int dp[510][510];
int visited[510][510];

void dfs(int x, int y){
    visited[x][y]= 1;

    if(x>0&&a[x][y]<a[x-1][y]){
        if(visited[x-1][y]==-1)
            dfs(x-1, y);
        dp[x][y]+=dp[x-1][y];
    }
    if(x+1<m&&a[x][y]<a[x+1][y]){
        if(visited[x+1][y]==-1)
            dfs(x+1, y);
        dp[x][y]+=dp[x+1][y];
    }
    if(y>0&&a[x][y]<a[x][y-1]){
        if(visited[x][y-1]==-1)
            dfs(x, y-1);
        dp[x][y]+=dp[x][y-1];
    }
    if(y+1<n&&a[x][y]<a[x][y+1]){
        if(visited[x][y+1]==-1)
            dfs(x, y+1);
        dp[x][y]+=dp[x][y+1];
    }
    
}

int main(){
    scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
            visited[i][j]= -1;
        }
    }

    // bottum-up 방법 사용해보자!
    // dp[i][j] = c
    // : (0, 0) -> (i, j)까지 c개의 경로가 있다
    // -> dp[m-1][n-1] 값이 (0, 0) -> (m-1, n-1) 까지 가는데 최종 경로 개수
    
    dp[0][0]= 1;
    dfs(m-1, n-1);
    
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         printf("%d ", dp[i][j]);
    //     }
    //     puts("");
    // }

    printf("%d\n", dp[m-1][n-1]);
}