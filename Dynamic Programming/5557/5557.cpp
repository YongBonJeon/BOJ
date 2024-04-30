#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
int seq[101];

// 확인한 수 / 중간 계산 결과
ll dp[101][25];

ll go(int idx, int val){
    if(val < 0 || val > 20)
        return 0;
    
    /*if(idx == N-2){
        if(val+seq[idx] == seq[idx+1] ||  val-seq[idx] == seq[idx+1])
            return 1;
        else if(val+seq[idx] != seq[idx+1] ||  val-seq[idx] != seq[idx+1])
            return 0;
    }*/
    if(idx == N-1){
        if(val == seq[idx])
            return 1;
        else
            return 0;
    }
    
    ll& ret = dp[idx][val];

    if(ret >= 0)
        return ret;

    ret = go(idx+1,val+seq[idx]) + go(idx+1,val-seq[idx]);
    //printf("%d %d %lld\n",idx,val,ret);
    return ret;
}

int main(){
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&seq[i]);

    memset(dp,-1,sizeof(dp));

    printf("%lld\n",go(1,seq[0]));

}