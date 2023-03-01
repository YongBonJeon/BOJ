#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    vector<pair<int,int>> v;

    scanf("%d",&N);
    int st,dt;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d %d",&st,&dt);
        v.push_back({dt,st});
    }
    sort(v.begin(),v.end());

    int ans = 0, cur = 0;
    for(auto x : v)
    {
        //printf("%d %d\n",x.second,x.first);
        if(cur > x.second)
            continue;
        ans++;
        cur = x.first;
    }
    printf("%d\n",ans);
}