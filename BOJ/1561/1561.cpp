#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N,M;
ll play[10001];

bool check(ll val){
    // val 초가 끝났을 때 탑승한 인원
    ll cnt = 0;
    for(int i = 0 ; i < M ; i++){
        cnt += val/play[i] + 1;
    }
    return N <= cnt;
}

int main(){
    scanf("%lld %lld",&N,&M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&play[i]);
    }

    ll left = 1, right = N*30,mid,ret = __LONG_LONG_MAX__;

    while(left <= right){
        mid = (left+right)/2;
        
        if(check(mid)){
            right = mid - 1;
            ret = min(ret,mid);
        }
        else{
            left = mid + 1;
        }
    }
    ll temp = 0;
    for(int i = 0 ; i < M ; i++)
        temp += (ret-1)/play[i] + 1;
    //printf("%lld %lld\n",ret-1,temp);
    if(ret-1 == 0){
        temp = 0; ret = 0;}
    for(int i = 0 ; i < M ; i++){
        if(ret%play[i] == 0)
            temp++;
        if(temp == N){
            printf("%d\n",i+1);
            return 0;
        }
    }
    //printf("%lld\n",ret);
    
    /*int child = 0, sec = 0;
    while(1){
        for(int i = 0 ; i < M ; i++){
            if(!sec){
                child++;
            }
            else{
                if((sec%play[i]) == 0){
                    child++;
                } 
            }
            if(child == N){
                printf("%d\n",i+1);
                return 0;
            }
        }
        sec++;
    }*/
}