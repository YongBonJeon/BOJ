#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int N,C;
int info[31];

map<pair<int,int>,ll> dp;

ll dfs(int idx, int sum){
    ll& ret = dp[{idx,sum}];

    if(idx == N)
        return 1;

    if(ret)
        return ret;

    // 넣을 수 있다면 넣는다
    if(sum+info[idx] <= C){
        ret += dfs(idx+1, sum+info[idx]);
    }
    // 안넣는다
    ret += dfs(idx+1, sum);

    return ret;
}

int main(){
    scanf("%d %d",&N, &C);
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&info[i]);

    printf("%lld\n",dfs(0,0));
}