#include<stdio.h>

char name[500010][20];
int idx[500010];
int aaaa[500010];

// int cmp_name(int tmp1, int tmp2){ 
//     // compare name[idx[tmp1]] and name[idx[tmp2]]
//     // return val 0 : name[idx[tmp1]] < name[idx[tmp2]]
//     // return val 1 : name[idx[tmp1]] > name[idx[tmp2]]
//     // return val 2 : name[idx[tmp1]] = name[idx[tmp2]]
//     int i;
//     for(i=0; name[idx[tmp1]][i]; i++){
//         if(name[idx[tmp1]][i]<name[idx[tmp2]][i])
//             return 0;
//         if(name[idx[tmp1]][i]>name[idx[tmp2]][i])
//             return 1;
//     }
//     if(!name[idx[tmp1]][i]&&!name[idx[tmp2]][i])
//         return 2;
//     return 0;
// }


int cmp_name(char* name1, char* name2){ 
    // compare name[idx[tmp1]] and name[idx[tmp2]]
    // return val 0 : name[idx[tmp1]] < name[idx[tmp2]]
    // return val 1 : name[idx[tmp1]] > name[idx[tmp2]]
    // return val 2 : name[idx[tmp1]] = name[idx[tmp2]]
    int i;
    for(i=0; name1[i]; i++){
        if(name1[i]<name2[i])
            return 0;
        if(name1[i]>name2[i])
            return 1;
    }
    if(!name1[i]&&!name2[i])
        return 2;
    return 0;
}

void merge(int min, int mid, int max){
    int idx2[500010];
    int tmp1, tmp2, tmp3;
    tmp1= min;
    tmp2= mid+1;
    tmp3= min;

    while(tmp1<=mid&&tmp2<=max){
        if(!cmp_name(name[idx[tmp1]], name[idx[tmp2]]))
            idx2[tmp3++]= idx[tmp1++];
        else
            idx2[tmp3++]= idx[tmp2++];
    }
    while(tmp1<=mid)
        idx2[tmp3++]= idx[tmp1++];
    while(tmp2<=max)
        idx2[tmp3++]= idx[tmp2++];
    for(tmp3= min; tmp3<=max; tmp3++)
        idx[tmp3]= idx2[tmp3];
    return;
}

void mergesort(int min, int max){
    if(min>=max) return;
    int mid= (min+max)/2;
    mergesort(min, mid);
    mergesort(mid+1, max);
    merge(min, mid, max);
}

void find(char* target, int min, int max){
    if(min>max) return;
    int mid= (min+max)/2;
    int k= cmp_name(target, name[idx[mid]]);
    // printf("\ncompare %s %s %d\n", target, name[idx[mid]], k);
    if(k==2)
        aaaa[mid]= 1;
    else if(!k)
        find(target, min, mid-1);
    else find(target, mid+1, max);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%s", name[i]);
        idx[i]= i;
    }

    mergesort(0, n-1);
    for(int i=0; i<m; i++){
        char target[20];
        scanf("%s", target);
        find(target, 0, n-1);
    }
    int ans= 0;
    for(int i=0; i<n; i++){
        ans+=aaaa[i];
    }
    printf("%d\n", ans);
    for(int i=0; i<n; i++){
        if(aaaa[i])
            printf("%s\n", name[idx[i]]);
    }
}