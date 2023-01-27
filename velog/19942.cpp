#include <bits/stdc++.h>
using namespace std;

int N, mp,mf,ms,mv;
int val[20][5];
int min_ = 100000;
vector<vector<int>> ans;

bool cmp(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

void select(int st, int num, vector<int> idx)
{    
    int p = 0,f = 0,s = 0,v = 0, cost = 0;
    //printf("idx ");
    for(auto i : idx)
    {
        p += val[i][0];
        f += val[i][1];
        s += val[i][2];
        v += val[i][3];
        cost += val[i][4];
        //printf("%d ",i);
    }
    //printf("\n");
    //printf("%d %d %d %d %d %d\n", num, p,f,s,v,cost);
    if(p >= mp && f >= mf && s >= ms && v >= mv)
    {
        if(min_ > cost)
        {
            min_ = cost;
            ans.clear();
            ans.push_back(idx);
        }
        else if(min_ == cost)
            ans.push_back(idx);
    }


    for(int i = st ; i < N ; i++)
    {
        //if(val[i][0] == 0 && val[i][1] == 0 && val[i][2] == 0 && val[i][3] == 0)
        //    continue;
        idx.push_back(i);
        select(i+1, num+1,idx);
        idx.pop_back();
    }
    
}

int main()
{
    scanf("%d",&N);
    scanf("%d %d %d %d",&mp, &mf, &ms, &mv);

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < 5 ; j++)
        scanf("%d",&val[i][j]);

    vector<int> idx;
    select(0,0,idx);

    sort(ans.begin(), ans.end());

    if(min_ == 100000){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",min_);
    for(auto y : ans[0])
    {
        printf("%d ",y+1);
    }
    printf("\n");
}
