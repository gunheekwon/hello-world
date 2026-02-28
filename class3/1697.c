#include<stdio.h>
#define MAX 100000
#define MIN 0

int a[200010];
int b[200010];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    
    int start, end;
    
    a[n]= 1;
    b[0]= n;
    start= 0;
    end= 1;
    while(!a[k]){
        int x = b[start];
        if(!a[x-1]&&x-1>=MIN&&x-1<=MAX){
            b[end]= x-1; 
            a[b[end]] = a[x]+1;
            end++;
        }
        if(!a[x+1]&&x+1>=MIN&&x+1<=MAX) {
            b[end]= x+1; 
            a[b[end]] = a[x]+1;
            end++;
        }
        if(x*2>=MIN&&x*2<=MAX&&!a[x*2]){
            b[end]= x*2; 
            a[b[end]] = a[x]+1;
            end++;
        }
        start++;
    }
    printf("%d\n", a[k]-1);
}