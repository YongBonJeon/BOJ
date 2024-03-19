#include <stdio.h>

long long dp[101];

int main(){

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    // dp[4] = dp[1]+dp[3]
    // dp[5] = dp[4]
    // dp[6] = dp[1]+dp[5]
    // dp[7] = dp[2]+dp[6]
    // dp[8] = dp[3]+dp[7]
    // dp[9] = dp[4]+dp[8]
    // dp[10] = dp[5]+dp[9]
    // dp[11] = dp[6]+dp[10] 

    int test_num;

    scanf("%d ",&test_num);

    while(test_num > 0){
        int n;
        scanf("%d",&n);
        for(int i = 6 ; i <= n ; i++){
            dp[i] = dp[i-5] + dp[i-1];
        }
        printf("%lld\n",dp[n]);

        --test_num;
    }
}