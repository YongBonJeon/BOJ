#include <bits/stdc++.h>
using namespace std;

int N,L;
vector<pair<int,int>> water;

int main()
{
    scanf("%d %d",&N, &L);

    int st,dt;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d %d",&st, &dt);
        water.push_back({st,dt});
    }
    sort(water.begin(),water.end());

    int result = 0, temp,cur  = 0;
    int last = 0;
    for(auto x : water)
    {
        if(last >= x.second)
            continue;
        cur = max(last, x.first);

        temp = (x.second-cur-1) / L + 1;
        result += temp;
        last = cur + temp*L;

        //printf("%d %d\n",cur,last);
    }
    printf("%d\n",result);
}