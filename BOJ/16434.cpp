#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct _room{
    ll t;
    ll a;
    ll h;
}room;

ll N,atk;
room rooms[123456];

bool check(ll val){
    ll hp = val;
    ll t_atk = atk;
    for(ll i = 0 ; i < N ; i++){
        ll t = rooms[i].t;
        ll a = rooms[i].a;
        ll h = rooms[i].h;
        if(t == 1){
            if(h%t_atk)
                hp -= a*(h/t_atk);
            else
                hp -= a*((h/t_atk)-1);
            //printf("hp %lld and atack %lld\n",val,a*(t_atk));
            //printf("%lld\n",hp);

            if(hp <= 0)
                return false;
            //printf("%lld %lld\n",i, hp);
        }
        else if(t == 2){
            t_atk += a;
            hp += h;
            
            hp = min(hp,val);

            //prllf("%d %d\n",i, hp);
        }
    }
    //printf("true \n");
    return true;
}

int main(){
    scanf("%lld %lld",&N,&atk);
    ll t,a,h;
    ll left,right = 0,mid;
    for(ll i = 0 ; i < N ; i++){
        scanf("%lld %lld %lld",&t, &a, &h);
        rooms[i].t = t;
        rooms[i].a = a;
        rooms[i].h = h;

        right += a*(h/atk)+1;
    }

    left = 1;
    ll ret = __LONG_LONG_MAX__;
    //printf("%lld\n",right);
    //printf("999999000001\n");
    while(left <= right){
        mid = (left+right)/2;

        //printf("mid %lld\n",mid);
        if(check(mid)){
            right = mid - 1;
            ret = min(ret,mid);
        }
        else
            left = mid + 1;
    }
    printf("%lld\n",ret);

    
}