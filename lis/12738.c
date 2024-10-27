#include<stdio.h>

int a[1000010];
int d[1000010];
int last_index;

int lower_bound(int s, int e, int k){
    // printf("(%d %d) %d\n", s, e, k);
    int m;
    while(e>s){
        m= (s+e)/2;
        // printf("(%d %d %d) %d - %d\n", s, m, e, d[m], k);

        if(d[m]<k) s= m+1;
        else e= m;
    }
    return e;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    d[0]= a[0];
    last_index= 0; 
    for(int i=1; i<n; i++){
        if(d[last_index]<a[i]){
            d[++last_index]=a[i];
        }else{
            int tmp= lower_bound(0, last_index, a[i]);
            d[tmp]= a[i];
        }

        // for(int j=0; j<=last_index; j++){
        //     printf("%d ", d[j]);
        // }
        // puts("");
    }

    printf("%d\n", last_index+1);
}