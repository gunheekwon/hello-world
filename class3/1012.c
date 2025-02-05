#include<stdio.h>

int map[52][52];

void clear_map(){
    for(int i=0; i<=50; i++)
        for(int j=0; j<=50; j++)
            map[i][j]= 0;
    return;
}

void visit(int x, int y, int cnt){
    map[x][y]= cnt;
    if(map[x-1][y]==-1)
        visit(x-1, y, cnt);
    if(map[x+1][y]==-1)
        visit(x+1, y, cnt);
    if(map[x][y-1]==-1)
        visit(x, y-1, cnt);
    if(map[x][y+1]==-1)
        visit(x, y+1, cnt);
    return;
}

void solve(){
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    clear_map();
    for(int i=0; i<k; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        map[x+1][y+1]= -1;
    }
    int cnt= 0;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(map[i][j]==-1)
                visit(i, j, ++cnt);
        }
    }
    printf("%d\n", cnt);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        solve();
    }
}