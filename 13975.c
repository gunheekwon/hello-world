#include<stdio.h>

int abs(int x){
    return x>0?x:-x;
}

int f(int *a, int *sum, int s, int e){
    if(s>=e) return a[s];
    if(s+1==e) return a[s]+a[e];

    int ne, tmp, tot;
    ne= s;
    tot= sum[e]-sum[s-1];
    tmp= abs(tot-a[s]);
    
    while(tmp<abs(tmp-a[ne+1])){
        ne++;
    }

    return f(a, sum, s, ne) + f(a, sum, ne+1, e);
}

int main(){
    int t, k;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        scanf("%d", &k);
        int a[k+2], sum[k+2], ans;
        
        sum[0]= 0;
        for(int j=1; j<=k; j++){
            scanf("%d", &a[j]);
            sum[j]= a[j]+sum[j-1];
        }
        
        printf("%d\n", f(a, sum, 1, k));
    }

}