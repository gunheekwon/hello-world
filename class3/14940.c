#include<stdio.h>
#include<queue>
using namespace std;

struct pair{
    int x;
    int y;
}

int map[1010][1010];
int ans[1010][1010];

int main(){
    int n, m;
    int start_x, start_y;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j]==0) ans[i][j]= 0;
            else if(map[i][j]==2) ans[i][j]= 0, start_x= i, start_y= j;
            else ans[i][j]= -1;
        }
    }

    queue<pair> q;
    q.push({start_x, start_y});
    while(!q.empty()){
        pair p = q.front();
        
    }

}