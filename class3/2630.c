#include<stdio.h>

int a[300][300];
int b[8]= {1, 2, 4, 8, 16, 32, 62, 128};

int blue_cnt= 0;
int white_cnt= 0;

void cnt(int minx, int miny, int maxx, int maxy){
    if(minx==maxx){
        if(a[minx][miny]==1) blue_cnt++;
        else white_cnt++;
        return;
    }
    int midx= (minx+maxx)/2;
    int midy= (miny+maxy)/2;
    cnt(minx, miny, midx, midy);
    cnt(midx+1, miny, maxx, midy);
    cnt(minx, midy+1, midx, maxy);
    cnt(midx+1, midy+1, maxx, maxy);
    
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    cnt(0, 0, n-1, n-1);
    printf("%d\n%d\n", white_cnt, blue_cnt);
}