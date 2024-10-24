#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int a[n+1];
    for(int i=0; i<=n; i++)
        a[i]= -1;
    
    a[3]= 1;
    a[5]= 1;
    for(int i=6; i<=n; i++){
        if(a[i-3]!=-1){
            a[i]= a[i-3]+1;
        }
        if(a[i-5]!=-1){
            a[i]= a[i-5]+1;
        }
    }

    printf("%d\n", a[n]);
    
}