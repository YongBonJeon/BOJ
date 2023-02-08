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

    int result = 0;
    int last = 0;
    for(auto x : water)
    {
        int t;

        if(last >= x.second)
            continue;

        last = max(last+1, x.first);

        printf("long %d \n",x.second-last+1);
        result += (x.second-last+1)/L + 1;
        last = (x.second-last+1)%L;
        if(last != 0)
            last = L - last;
        last += x.second;
        printf("%d\n",last);
    }
    printf("%d\n",result);
}