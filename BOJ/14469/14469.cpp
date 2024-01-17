#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> cow;

int main()
{
    int N;

    scanf("%d",&N);

    int st, w;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d %d",&st, &w);

        cow.push_back({st,w});
    }
    sort(cow.begin(),cow.end());

    int cur = 0;

    for(auto x : cow)
    {
        printf("%d %d\n",x.first, x.second);
        if(cur < x.first)
            cur = x.first;
        cur += x.second;
    }
    printf("%d\n",cur);
}