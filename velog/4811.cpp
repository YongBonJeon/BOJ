#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll dp[100][100][100];

ll drug(ll idx,ll num, ll half){
    if(idx == 2*n)
        return 1;
    
    ll& ret = dp[idx][num][half];
    if(ret > 0)
        return ret;

    // 한 조각을 꺼낸 경우
    if(num > 0)
        ret += drug(idx+1,num-1,half+1);
    // 반 조각을 꺼낸 경우
    if(half > 0)
        ret += drug(idx+1,num,half-1);

    return ret;
}

int main(){
    while(1){
        scanf("%d",&n);
        if(!n)
            break;
        memset(dp,0,sizeof(dp));
        printf("%lld\n",drug(0,n,0));
    }
}