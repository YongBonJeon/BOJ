#include <bits/stdc++.h>
using namespace std;

int N, min_ = INT_MAX;
int m[11][11];
int visited[11];
int population[11];

vector<int> section;
vector<int> other;

int solve()
{
    queue<int> q;
    int cur = section[0], next;
    q.push(cur);
    visited[cur] = 1;

    while(!q.empty())
    {
        cur = q.front(); q.pop();

        for(int i = 0 ; i < N ; i++)
        {
            if(m[cur][i])
                next = i;
            else
                continue;
            if(!visited[next] && find(section.begin(), section.end(), next) != section.end())
            {
                visited[next] = 1;
                q.push(next);
            }
        }
    }

    cur = other[0];
    q.push(cur);
    visited[cur] = 1;

    while(!q.empty())
    {
        cur = q.front(); q.pop();

        for(int i = 0 ; i < N ; i++)
        {
            if(m[cur][i])
                next = i;
            else
                continue;
            if(!visited[next] && find(other.begin(), other.end(), next) != other.end())
            {
                visited[next] = 1;
                q.push(next);
            }
        }
    }


    for(int i = 0 ; i < N ; i++)
        if(!visited[i])
            return -1;

    int ret = 0;
    for(auto x : section)
    {
        ret += population[x];
    }
    for(auto y : other)
    {
        ret -= population[y];
    }

    return abs(ret);
}

void divide(int st)
{
    if(section.size() && section.size() != N){
        other.clear();
        for(int i = 0 ; i < N ; i++)
        {
            if(find(section.begin(), section.end(), i) == section.end())
                other.push_back(i);
        }
        
        int ans;
        memset(visited,0,sizeof(visited));
        if((ans = solve()) != -1)
        {
            min_ = min(min_, ans);
        }
    }
    

    for(int i = st ; i < N ; i++)
    {
        section.push_back(i);
        divide(i+1);
        section.pop_back();
    }
}

int main()
{
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&population[i]);
    for(int i = 0 ; i < N ; i++)
    {
        int M,temp;
        scanf("%d",&M);
        for(int j = 0 ; j < M ; j++)
        {
            scanf("%d",&temp);
            m[i][temp-1] = 1;
        }
    }
    for(int i = 0 ; i < N ; i++)
    /*{
        for(int j = 0 ; j < N ; j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }*/

    divide(0);
    


    if(min_ == INT_MAX)
    {
        printf("-1\n");
        return 0;
    }
    
    printf("%d\n",min_);
}