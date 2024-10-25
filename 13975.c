#include<stdio.h>
// gg 몰?루
// 처음부터 안 합쳐도 됨 <- 요거를 고려하지 않았음
// 순서 상관 없이 합칠 수 있다는 것을 고려해서 다시 풀어보자!
int tot_ans= 0;

int abs(int x){
    return x>0?x:-x;
}

int f(int *a, int *sum, int s, int e){
    if(s>=e) return a[s];
    if(s+1==e) {
        return a[s]+a[e];
    }

    int ne, tmp1, tmp2, tmp3, min;
    ne= s;
    tmp1= 0;
    tmp2= sum[e]-sum[s-1];
    min= abs(tmp1-tmp2);
    for(int j= s; j<e; j++){
        tmp1+=a[j];
        tmp2-=a[j];
        tmp3= abs(tmp1-tmp2);
        if(min>tmp3){
            min= tmp3;
            ne= j;
        }
    }
    int ans1, ans2;
    ans1= f(a, sum, s, ne);
    ans2= f(a, sum, ne+1, e);
    printf("f(%d, %d) \tans1: %d \t(%d, %d)\n", s, e, ans1, s, ne);
    printf("f(%d, %d) \tans2: %d \t(%d, %d)\n", s, e, ans2, ne+1, e);
    if(s!=ne) tot_ans+=ans1;
    if(ne+1!=e) tot_ans+=ans2;
    return ans1+ans2;
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
        printf("%d\n", tot_ans);
    }

}