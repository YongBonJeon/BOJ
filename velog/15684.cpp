#include <bits/stdc++.h>
using namespace std;

int N,M,H;
int min_ = 9999;

vector<pair<int,int>> path[31];

int go(int v,int level)
{
    if(level == H+1)
        return v;

    for(auto x : path[level])
    {
        if(x.first == v)
        {
            return go(x.second, level+1);;
        }
    }
    return go(v,level+1);
}

void add_ladder(int level, int num)
{
    if(level > H)
        return ;

    if(num <= 3)
    {
        int success = 1;
        for(int i = 1 ; i <= N ; i++)
        {
            int temp;
            if((temp = go(i,0)) != i){
                success--;
                break;
            }
        }
        if(success){
            //printf("%d %d\n",path[H].back().first, path[H].back().second);
            if(min_ > num)
                min_ = num;
            return ;
        }
    }
    else
        return ;

    /*for(int i = 1 ; i <= H ; i++)
    {
        for(int j = 1 ; j < N ; j++)
        {
            bool add = 1;
            for(auto x : path[i])
            {
                if(x.first == i)
                    add = 0;
                if(x.first == i-1)
                    add = 0;
            }
            if(add)
            {
                path[i].push_back({i,i+1});
                path[i].push_back({i+1,i});
                add_ladder(level, num+1);
                path[level].pop_back();
                path[level].pop_back();
            }
        }
    }*/

    for(int i = 1 ; i < N ; i++)
    {
        bool add = 1;
        for(auto x : path[level])
        {
            if(x.first == i)
                add = 0;
            if(x.first == i-1)
                add = 0;
            if(x.first == i+1)
                add = 0;
        }
        if(add)
        {
            path[level].push_back({i,i+1});
            path[level].push_back({i+1,i});
            add_ladder(level, num+1);
            path[level].pop_back();
            path[level].pop_back();
        }
    }
    add_ladder(level+1, num);
}

int main()
{
    scanf("%d %d %d",&N, &M, &H);

    int level, v;
    for(int i = 0 ; i < M ; i++)
    {
        scanf("%d %d",&level, &v);
        path[level].push_back({v,v+1});
        path[level].push_back({v+1,v});
    }

    add_ladder(1,0);
    if(min_ != 9999)
        printf("%d\n",min_);
    else
        printf("-1\n");

}