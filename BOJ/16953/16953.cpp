#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<ll,ll> dp;

int main(){
    ll A,B;

    scanf("%lld %lld",&A,&B);

    dp[A] = 0;

    queue<ll> q;

    q.push(A);

    ll cur, next;
    while(!q.empty()){
        cur = q.front(); q.pop();
        if(cur == B) break;
        if(cur > B) continue;
        //printf("%lld\n",cur);

        next = cur*2;
        if(dp[next] == 0){
            dp[next] = dp[cur] + 1;
            q.push(next);
        }
        next = (cur*10)+1;
        if(dp[next] == 0){
            dp[next] = dp[cur] + 1;
            q.push(next);
        }
    }
   
    if(dp[B] == 0) printf("-1\n");
    else printf("%lld\n",dp[B]+1);
}