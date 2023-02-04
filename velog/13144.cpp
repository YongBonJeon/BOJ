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

    long long ans = N*(N+1)/2;

    long long l = 0, r = 0;
    /*check[s[l]] = 1;

    while(r < N)
    {
        //printf("%d %d\n",l,r);
        if(check[s[r]] > 1)
        {
            ans -= N-r;
            check[s[l]]--;
            l++;
        }
        else
        {
            r++;
            check[s[r]]++;
        }
    }*/

    while(r < N)
    {
        if(!check[s[r]])
        {
            check[s[r]]++;
            r++;
        }
        else
        {
            ans -= N-r;
            check[s[l]]--;
            l++;
        }
    }
    printf("%lld\n",ans);
}