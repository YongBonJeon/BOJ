#include <bits/stdc++.h>
using namespace std;

int N;
stack<pair<long long, long long>> s;

int main()
{
    scanf("%d",&N);

    long long t,cnt;
    long long ans = 0;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%lld",&t);

        cnt = 1;
        while(!s.empty() && s.top().first <= t){
            ans += s.top().second;

            if(s.top().first == t){
                cnt = s.top().second + 1;
            }
            else
                cnt = 1;
            s.pop();
        }
        if(!s.empty())
            ans++;
        s.push({t,cnt});
    }
    printf("%lld\n",ans);

}