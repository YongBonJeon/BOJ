#include <stdio.h>

int n;
int value[1001];
int dp[1001];


int main(){
    scanf("%d",&n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d",&value[i]);
        dp[i] = 10000;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            if(dp[i] > dp[i-j] + value[j]){
                dp[i] = dp[i-j] + value[j];
            }
        }
    }
    /*int min = 0;

    for(int i = 1 ; i<=n ; i++){
        printf("%d ",dp[i]);
        if(min < dp[i]){
            min = dp[i];
        }
    }*/
    printf("%d\n",dp[n]);






}