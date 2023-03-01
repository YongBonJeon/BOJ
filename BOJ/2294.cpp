#include <bits/stdc++.h>
using namespace std;

int n,k;
int dp[100001];

int main(){
    scanf("%d %d",&n, &k);

    for(int i = 0 ; i <= k ; i++)
        dp[i] = INT_MAX;

    int t;
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&t);
        dp[t] = 1;
    }

    for(int i = 1 ; i <= k ; i++){
        for(int j = 1 ; j < i ; j++){
            if(dp[j] != INT_MAX && dp[i-j] != INT_MAX)
                dp[i] = min(dp[i],dp[j] + dp[i-j]);
        }
    }

    if(dp[k] == INT_MAX)
        printf("-1\n");
    else
        printf("%d\n",dp[k]);

}