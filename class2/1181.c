#include<stdio.h>

char words[20001][51];
int idx[20001];
int idx2[20001];
int len[20001];

int cmp(int x, int y){
    if(len[idx[x]]<len[idx[y]])
        return 0;
    else if(len[idx[x]]>len[idx[y]])
        return 1;

    for(int i= 0; words[idx[x]][i]; i++){
        if(words[idx[x]][i]<words[idx[y]][i])
            return 0;
        else if(words[idx[x]][i]>words[idx[y]][i])
            return 1;
    }

    return 0; // same
}

int is_same(int x, int y){
    if(len[idx[x]]!=len[idx[y]])
        return 0;

    for(int i= 0; words[idx[x]][i]; i++){
        if(words[idx[x]][i]!=words[idx[y]][i])
            return 0;
    }
    return 1;
}

void get_words(int n){
    for(int i=0; i<n; i++){
        scanf("%s", words[i]);
        idx[i]= i;
        int j;
        for(j=0; words[i][j+1]; j++);
        len[i]= j;
    }
    return;
}

void print_words(int n, int m){
    for(int i=n; i<=m; i++){
        printf("%s\n", words[idx[i]]);
    }
}

void print_ans(int n){
    printf("%s\n", words[idx[0]]);
    for(int i=1; i<n; i++){
        if(is_same(i-1, i)){
            continue;     
        }else
            printf("%s\n", words[idx[i]]);
    }
}

void merge(int min, int mid, int max){
    int i, j, k;
    i= min;
    j= mid+1;
    k= min;
    // printf("**merge %d %d %d**\n", min, mid, max);
    // print_words(min, mid);
    // print_words(mid+1, max);

    while(i<=mid&&j<=max){
        if(!cmp(i, j))
            idx2[k++]= idx[i++];
        else
            idx2[k++]= idx[j++];
    }
    while(i<=mid)
        idx2[k++]= idx[i++];
    while(j<=max)
        idx2[k++]= idx[j++];

    for(k= min; k<=max; k++)
        idx[k]= idx2[k];

    // printf("**merge result**\n");
    // print_words(min, max);

    return;
}

void merge_sort(int min, int max){
    if(min>=max)
        return;
    int mid= (min+max)/2;
    merge_sort(min, mid);
    merge_sort(mid+1, max);
    merge(min, mid, max);
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    get_words(n);
    // puts("--chk input--");
    // print_words(0, n-1);
    merge_sort(0, n-1);
    // puts("--ans--");
    // print_words(0, n-1);
    print_ans(n);
}