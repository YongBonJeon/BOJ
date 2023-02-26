#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,K;
// 구간 수 / 중간 시간합
int dp[101][100001];
pair<int,int> cycle[101];
pair<int,int> running[101];

int go(int idx, int sum){
    if(idx == N){
        return 0;
    }

    int& ret = dp[idx][sum];
    if(ret)
        return ret;
    
    ret = -1e6;
    if(sum - cycle[idx].first >= 0)
        ret = max(ret,go(idx+1,sum-cycle[idx].first)+cycle[idx].second);
    if(sum - running[idx].first >= 0)
        ret = max(ret,go(idx+1,sum-running[idx].first)+running[idx].second);

    return ret;
}

int main(){
    scanf("%d %d",&N,&K);
    for(int i = 0 ; i < N ; i++){
        scanf("%d %d %d %d",&running[i].first,&running[i].second,&cycle[i].first,&cycle[i].second);
    }
    memset(dp,0,sizeof(dp));
    printf("%d\n",go(0,K));
}

/*
dp[1][200] = 100
dp[1][500] = 200

dp[2][1000] = 470
dp[2][1300] = 570
dp[2][800] = 320
dp[2][500] = 220
*/