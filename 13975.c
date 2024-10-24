#include<stdio.h>

int abs(int x){
    return x>0?x:-x;
}

int f(int *a, int *sum, int s, int e){
    printf("f(%d, %d)\n", s, e);
    if(s>=e) return a[s];
    if(s+1==e) return a[s]+a[e];

    int ne, tmp, min, tot;
    tot= sum[e]-sum[s-1];
    ne= s;
    tmp= 0;
    for(int j= s; j<e; j++){
        tmp+=a[j];
        if(min>abs(tot-2*tmp)){
            min= abs(tot-2*tmp);
            ne= j;
        }
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
        
        printf("%d\n", sum[k]+f(a, sum, 1, k));
    }

}