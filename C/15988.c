#include <stdio.h>

/*
 *  a[1] = 1; a[2] = 2 a[3] = 4 
 */
long long dp[1000001];

void do_dp(int n){
    for(int i = 4 ; i <= n ; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%1000000009;
    }
}
int main(){
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;

    int test;
    scanf("%d",&test);

    for(int i = 0 ; i < test ; i++){
        int n;
        scanf("%d",&n);

        do_dp(n);

        printf("%lld\n",dp[n]);
    }
}