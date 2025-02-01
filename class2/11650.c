#include<stdio.h>

typedef struct loc
{
    int x;
    int y;
} locType;

locType array[100010];

void merge(int start, int mid, int end){
    locType array2[100010];
    int tmp1= start;
    int tmp2= mid+1;
    int tmp3= start;
    
    while(tmp1<=mid && tmp2<=end){
        if(array[tmp1].x < array[tmp2].x)
            array2[tmp3++]= array[tmp1++];
        else if(array[tmp1].x == array[tmp2].x){
            if(array[tmp1].y < array[tmp2].y)
                array2[tmp3++]= array[tmp1++];
            else
                array2[tmp3++]= array[tmp2++];
        }else
            array2[tmp3++]= array[tmp2++];
    }

    while(tmp1<=mid)
        array2[tmp3++]= array[tmp1++];

    while(tmp2<=end)
        array2[tmp3++]= array[tmp2++];

    for(tmp3= start; tmp3<=end; tmp3++)
        array[tmp3]= array2[tmp3];
    
    return;
}

void mergeSort(int start, int end){
    if(start>=end) return;
    int mid= (start+end)/2;

    mergeSort(start, mid);
    mergeSort(mid+1, end);
    merge(start, mid, end);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x, y;
        scanf("%d %d", &array[i].x, &array[i].y);
    }

    mergeSort(0, n-1);

    for(int i=0; i<n; i++){
        printf("%d %d\n", array[i].x, array[i].y);
    }
}