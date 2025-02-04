#include<stdio.h>

int main(){
    int S= 0;
    int all= (1<<21)-1;
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        char cmd[10];
        scanf("%s", cmd);
        if(cmd[0]=='e') // empty
            S= 0;
        else if(cmd[0]=='a'&&cmd[1]=='l') // all
            S= all;
        else{
            int k;
            scanf("%d", &k);
            switch(cmd[0]){
                case 'a': //add
                    S = S|1<<k;
                    break;
                case 'r': //remove
                    S = S&(all-(1<<k));
                    break;
                case 'c': //check
                    printf("%d\n", (S&1<<k)?1:0);
                    break;
                case 't': //toggle
                    S= S^1<<k;
                    break;
                default:
                    puts("error!");
            }
        }
    }
}