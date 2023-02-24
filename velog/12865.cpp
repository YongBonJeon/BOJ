#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K,w,v;
    int dp[100001];

    scanf("%d %d",&N, &K);
    
    memset(dp,0,sizeof(dp));
    while(N--){
        scanf("%d %d",&w, &v);

        for(int j = K ; j >= w ; j--){
            dp[j] = max(dp[j], dp[j-w]+v);
        }
    }
    printf("%d\n",dp[K]);

    return 0;
}
