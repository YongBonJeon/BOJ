#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<pair<int,int>> pq;
int parent[200001];

int find(int s)
{
    if(s == parent[s])
        return s;
    return parent[s] = find(parent[s]);
}

void merge(int u,int v)
{
    parent[v] = u;
}

int main()
{   
    scanf("%d",&N);

    for(int i = 0 ; i <= N ; i++)
        parent[i] = i;

    int d,w,ans = 0;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d %d",&d,&w);

        pq.push({w,d});
    }

    for(int i = 0 ; i < N ; i++)
    {
        int avail = find(pq.top().second);

        if(avail > 0)
        {
            merge(find(avail-1),avail);
        
            ans += pq.top().first;
        }
        pq.pop();
    }
    printf("%d\n",ans);
}
  