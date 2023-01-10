#include <bits/stdc++.h>
using namespace std;

int N,C;

bool compare(pair <int, pair<int, int>> &a, pair <int, pair<int, int>> &b)
{
    if(a.second.first != b.second.first)
        return a.second.first > b.second.first;
    else{
        //printf("x");
        return a.second.second < b.second.second;
    }
}

int main()
{
    scanf("%d %d",&N, &C);

    map<int, pair<int, int>> m;
    vector<int> idx;
    
    int temp;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&temp);

        if(m.find(temp) == m.end())
        {
            m.insert({temp,{1,i}});
            //idx.push_back(temp);
        }
        else
        {
            m.find(temp)->second.first++;
        }
    }

    vector<pair<int, pair<int, int>>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),compare);

    for(auto it = v.begin() ; it != v.end() ; it++)
    {
        for(int i = 0 ; i < it->second.first ; i++)
            printf("%d ",it->first);
        //printf("%d %d %d\n",it->first, it->second.first, it->second.second);
    }
    printf("\n");
}