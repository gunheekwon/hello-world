#include<stdio.h>

int paper[200][200];
int white[200][200];
int blue[200][200];

void f(int sx, int sy, int ex, int ey){
    if(sx==ex&&sy==ey) return;
    int mx= (sx+ex)/2;
    int my= (sy+ey)/2;
    f(sx, sy, mx, my);
    f(mx+1, sy, ex, my);
    f(sx, my+1, mx, ey);
    f(mx+1, my+1, ex, ey);

    // chk [mx][my], [ex][my], [mx][ey], [ex][ey]
    white[ex][ey] = white[mx][my]+white[ex][my]+white[mx][ey]+white[ex][ey];
    blue[ex][ey] = blue[mx][my]+blue[ex][my]+blue[mx][ey]+blue[ex][ey];
    if(white[ex][ey]==0) blue[ex][ey]= 1; // no white paper = all blue
    if(blue[ex][ey]==0) white[ex][ey]= 1; // no blue paper = all white
    return;
}


int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &paper[i][j]);
            if(paper[i][j]) blue[i][j]= 1;
            else white[i][j]= 1;
        }
    }
    f(0, 0, n-1, n-1);
    printf("%d\n%d\n", white[n-1][n-1], blue[n-1][n-1]);
}