#include <bits/stdc++.h>
using namespace std;

vector<int> adj[51];
vector<int> visited(51);
int N, del;

int dfs(int v)
{   
    int next, ans = 0;
    visited[v] = 1;

    if(v == del)
        return 0;

    if(adj[v].size() == 0)
        return 1;

    for(int i = 0 ; i < adj[v].size() ; i++)
    {
        next = adj[v][i];

        if(!visited[next])
            ans += dfs(next);
    }

    return ans;
}

int main()
{
    scanf("%d",&N);

    int node, root;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&node);

        if(node == -1)
            root = i;
        else
        {
            adj[node].push_back(i);
        }
    }
    scanf("%d",&del);

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < adj[i].size() ; j++)
        {
            if(adj[i][j] == del)
                adj[i].erase(adj[i].begin() + j);
        }
    }

    printf("%d\n",dfs(root));
}
