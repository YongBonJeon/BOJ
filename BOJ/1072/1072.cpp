#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll X,Y,Z;

bool check(ll val){
    return Z != ((Y+val)*100)/(X+val);
}

int main(){
    scanf("%lld %lld",&X, &Y);

    Z = (Y*100/X);

    if(Z == 99){
        printf("-1\n");
        return 0;
    }

    ll l = 1, r = 2*X, mid,ret = __LONG_LONG_MAX__;
    while(l <= r){
        mid = (l+r)/2;

        if(check(mid)){
            r = mid -1;
            ret = min(ret, mid);
        }
        else
            l = mid + 1;
    }
    if(ret == __LONG_LONG_MAX__)
        printf("-1\n");
    else
        printf("%lld\n",ret);
}