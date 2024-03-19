#include <stdio.h>

#define MAX 10

int main(){
    int n, k;
    int value[MAX];
    int ifmax = 0;
    int ifmax_idx;
    int num = 0;

    scanf("%d %d",&n, &k);

    ifmax = 0;
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&value[i]);
        if(value[i] <= k){
            if(value[i] > ifmax)
                ifmax = value[i];
                ifmax_idx = i;
        }
    }
    
    while(k > 0 && ifmax_idx >= 0){
        int div = k/value[ifmax_idx];

        if(div == 0){
            ifmax_idx--;
            continue;
        }
        num+=div;
        k -= value[ifmax_idx--]*div;
        //printf("ss%d %d\n",k,div);
    }

    printf("%d\n",num);



}