#include<stdio.h>

int a[1000001];

int main(){
    int n;
    scanf("%d", &n);

    a[1]= 0;
    a[2]= 1;
    a[3]= 1;
    for(int i=2; i<n; i++){
        if(a[i]!=0){
            if(i+1<=n&&(a[i+1]==0||a[i+1]>a[i]+1))
                a[i+1]= a[i]+1;
                
            if(i*2<=n&&(a[i*2]==0||a[i*2]>a[i]+1))
                a[i*2]= a[i]+1;
                
            if(i*3<=n&&(a[i*3]==0||a[i*3]>a[i]+1))
                a[i*3]= a[i]+1;
        }
    }

    printf("%d\n", a[n]);
}