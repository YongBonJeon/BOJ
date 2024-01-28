#include <bits/stdc++.h>
using namespace std;

const int max_vertices = 20001;

vector<pair<int,int>> adj[max_vertices];
vector<int> dist(max_vertices);
int V,E;
int start;

struct cmp{
    bool operator()(const pair<int, int> a, const pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void path(int v)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    int cur, ds;
    pq.push({v,0});

    while(!pq.empty())
    {
        tie(cur,ds) = pq.top(); pq.pop();
        printf("cur %d %d\n",cur,ds);
        if(dist[cur] < ds)
            continue;

        int d, w;
        for(int  i = 0 ; i < adj[cur].size() ; i++)
        {
            tie(d,w) = adj[cur][i];

            if(dist[d] > dist[cur] + w){
                dist[d] = dist[cur] + w;
                pq.push({d, dist[cur]+w});
            }
        }
    }
}

int main()
{
    scanf("%d %d",&V, &E);
    scanf("%d",&start);

    int s, d, w;
    for(int i = 0 ; i < E ; i++)
    {
        scanf("%d %d %d",&s, &d, &w);

        adj[s].push_back({d,w});
    }

    for(int i = 1 ; i <= V ; i++)
        dist[i] = INT_MAX;
    dist[start] = 0;
    path(start);

    for(int i = 1 ; i <= V ; i++)
    {
        if(dist[i] == INT_MAX)
            printf("INF\n");
        else
            printf("%d\n",dist[i]);
    }
}