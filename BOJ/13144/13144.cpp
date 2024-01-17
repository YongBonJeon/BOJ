#include <bits/stdc++.h>
using namespace std;

long long N;
long long s[100001] = {0,};
long long check[100001] = {0,};


bool check_dup(int l, int r)
{
    for(int i = l ; i <= r ; i++)
    {
        if(check[s[i]] > 1)
            return false;
    }
    return true;
}

int main()
{
    scanf("%lld",&N);
    for(int i = 0 ; i < N ; i++)
        scanf("%lld",&s[i]);

    // 모든 경우의 수
    long long ans = N*(N+1)/2;

    long long l = 0, r = 0;

    while(r < N)
    {
        // s[r]이 추가된 새로운 수열
        if(!check[s[r]])
        {
            check[s[r]]++;
            r++;
        }
        else
        {
            // s[r]이 중복이 발생했을 때 
            // 현재 수열이 포함된 모든 경우의 수를 제거
            ans -= N-r;
            check[s[l]]--;
            l++;
        }
    }
    printf("%lld\n",ans);
}