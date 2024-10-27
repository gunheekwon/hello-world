#include<stdio.h>

int coin[110];
int value[10010];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++){
        scanf("%d", &coin[i]);
    }

    value[0]= 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(value[j]!=0 && j+coin[i]<=k)
                value[j+coin[i]]+=value[j];
        }
    }

    printf("%d\n", value[k]);
}