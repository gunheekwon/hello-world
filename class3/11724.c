#include<stdio.h>

int a[1010];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++) a[i]= i;

    for(int i=1; i<=m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if(a[x]!=a[y]){
            int min, max;
            min= a[x]<a[y]?a[x]:a[y];
            max= a[x]>a[y]?a[x]:a[y];
            for(int j=1; j<=n; j++){
                if(a[j]==max)
                    a[j]= min;
            }
        }
        
        // for(int k=1; k<=n; k++) printf("%d ", a[k]);
        // printf("\n");
    }

    int tmp= 0;
    int ans= 0;
    for(int i=1; i<=n; i++){
        if(tmp<a[i]){
            tmp= a[i];
            ans++;
        }
    }
    printf("%d\n", ans);

}