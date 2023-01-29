#include <bits/stdc++.h>
using namespace std;

int T,N,M;
vector<int> adj[1001];
int visited[1001];

void dfs(int v)
{
    //printf("v %d ",v);
    visited[v] = 1;

    for(auto next : adj[v])
    {
        if(!visited[next])
            dfs(next);
    }
}

int main()
{
    scanf("%d",&T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d %d",&N, &M);

        adj->clear();
        for(int j = 0 ; j < M ; j++)
        {
            int st, dt;

            scanf("%d %d",&st, &dt);
            adj[st].push_back(dt);
            adj[dt].push_back(st);
        }

        if(N != M+1){
            printf("graph\n");
            continue;
        }
        else
        {
            dfs(1);
            bool success = 1;
            for(int i = 1 ; i <= N ; i++)
            {
                if(!visited[i])
                    success = 0;
            }
            if(success)
                printf("tree\n");
            else
                printf("graph\n");
        }
        

    }
}