#include<stdio.h>

int a[101][101];
int visited[101];

void visit(int x, int n){
    // printf("visit %d\n", x);
    for(int i=1; i<=n; i++){
        if(!visited[i]&&a[x][i]){
            visited[i]= 1;
            visit(i, n);
        }
    }
    return;
}

void solve(int n){
    visited[1]= 1;
    visit(1, n);
    return;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y]= a[y][x]= 1;
    }
    solve(n);
    int ans= 0;
    for(int i=2; i<=n; i++){
        ans+=visited[i];
    }
    printf("%d\n", ans);
}