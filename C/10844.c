#include <stdio.h>

int dp[101];

int main(){
    dp[1] = 9;
    dp[2] = 17;
    dp[3] = 32;

    int n;
    int x = 3;

    scanf("%d",&n);

    for(int i = 4 ; i <= n ; i++){
        dp[i] = (dp[i-1]*2 - x*(i-3))%1000000000;
    }

    printf("%d\n",dp[n]);

    
}