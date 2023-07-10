#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

ll N,M;
vector<pair<ll,ll>> path[10001];
ll dp[10001];
ll maxnum = 987653210;

struct cmp{
    bool operator()(const pair<int, int> a, const pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int main(){
    scanf("%lld %lld",&N, &M);
    for(int i = 0 ; i < N ; i++) dp[i+1] = maxnum;

    ll s,e,w;
    for(int i = 0 ; i < M ; i++){
        scanf("%lld %lld %lld",&s,&e,&w);
        path[s].push_back({e,w});
    }

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, cmp> pq;

    scanf("%lld %lld",&s,&e);

    pq.push({s,0});
    dp[s] = 0;

    while(!pq.empty()){
        tie(s,w) = pq.top(); pq.pop();
        if(s == e) break;
        for(auto x : path[s]){
            
            if(dp[x.first] > x.second + dp[s]){
                dp[x.first] = x.second + dp[s];
                //printf("    %lld %lld\n",x.first,dp[x.first]);
                pq.push({x.first,dp[x.first]});
            }
        }
    }

    printf("%lld\n",dp[e]);
    
}