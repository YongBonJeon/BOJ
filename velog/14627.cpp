#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll S,C;
ll pa[1000001];

bool check(ll val){
    ll ans = 0;
    for(int i = 0 ; i < S ; i++){
        ans += pa[i]/val;
    }
    //printf("%lld %lld\n",val,ans);
    return C <= ans;
}

int main(){
    ll l = 1,r = 0,mid,ret = 0,sum = 0;
    scanf("%lld %lld",&S,&C);
    for(int i = 0 ; i < S ; i++){
        scanf("%lld",&pa[i]);
        r = max(r,pa[i]);
        sum += pa[i];
    }

    while(l <= r){
        mid = (l+r)/2;

        if(check(mid)){
            l = mid + 1;
            ret = max(ret,mid);
        }
        else
            r = mid - 1;
    }
    ll ans = sum - C*ret;
    
    printf("%lld\n",ans);
}