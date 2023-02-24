#include <bits/stdc++.h>
using namespace std;

int n,k;
int dp[100001];

int main(){
    scanf("%d %d",&n, &k);

    dp[0] = 1;
    int t;
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&t);
        
        for(int j = t ; j <= k ; j++)
            dp[j] += dp[j-t];
    }

    printf("%d\n",dp[k]);
}