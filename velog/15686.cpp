#include <bits/stdc++.h>
using namespace std;

int N,M;
int m[51][51];
int min_dist = INT_MAX;
vector<pair<int,int>> chicken;
vector<pair<int,int>> home;


int cal_dist(pair<int ,int> d1, pair<int, int> d2)
{
    return abs(d1.first-d2.first) + abs(d1.second-d2.second);
}

int all_dist(vector<pair<int, int>> shop)
{
    int total_dist = 0;
    for(auto h : home)
    {
        int min = INT_MAX, temp;
        for(auto s : shop)
        {
            if((temp = cal_dist(h, s)) < min)
            {
                min = temp;
            }
        }
        total_dist += min;
    }
    return total_dist;
}

void select(vector<pair<int,int>> shop, int start, int dist)
{
    //printf("t %d\n",dist);
    if(shop.size() && min_dist > dist)
            min_dist = dist;
    if(shop.size() == M){
        return ;
    }

    //for(auto ch : chicken)
    for(int i = start ; i < chicken.size() ; i++)
    {
        if(find(shop.begin(), shop.end(), chicken[i]) == shop.end()){
            shop.push_back(chicken[i]);
            select(shop, i+1, all_dist(shop));
            shop.pop_back();
        }
    }


}

int main()
{
    scanf("%d %d",&N, &M);

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            scanf("%d",&m[i][j]);
            if(m[i][j] == 2)
                chicken.push_back({i,j});
            else if(m[i][j] == 1)
                home.push_back({i,j});
        }
    }
    vector<pair<int, int>> temp;
    select(temp,0, 0);

    printf("%d\n",min_dist);
}