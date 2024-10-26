#include<stdio.h>

int zerocalled[41];
int onecalled[41];

int main(){
    int t;
    scanf("%d", &t);
    
    zerocalled[0]= 1;
    onecalled[1]= 1;
    for(int i=2; i<=40; i++){
        zerocalled[i]= zerocalled[i-2]+zerocalled[i-1];
        onecalled[i]= onecalled[i-2]+onecalled[i-1];
    }

    for(int i=0; i<t; i++){
        int n;
        scanf("%d", &n);
        printf("%d %d\n", zerocalled[n], onecalled[n]);
    }
}