#include<bits/stdc++.h>

using namespace std;

int N,C;
int arr[31];

void make_sum(int idx, int end, int sum, vector<int> &v){
    if(sum > C || sum > 1e9)
        return ;
    if(idx == end){
        v.push_back(sum);
        return ;
    }

    make_sum(idx+1, end, sum+arr[idx], v);
    make_sum(idx+1, end, sum, v);
}

int main(){
    scanf("%d %d",&N, &C);
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&arr[i]);

    vector<int> sum1, sum2;

    make_sum(0,N/2,0, sum1);
    make_sum(N/2,N,0, sum2);
    sort(sum1.begin(),sum1.end());
    sort(sum2.begin(),sum2.end());

    int ret = 0;
    for(auto x : sum1){
        if(C-x >= 0){
            int pos = upper_bound(sum2.begin(),sum2.end(),C-x) - sum2.begin();
            ret += (pos);
        }
    }
    printf("%d\n",ret);
}

/*typedef long long ll;

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
}*/