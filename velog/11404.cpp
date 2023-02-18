#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> adj[101];
int dist[101][101];

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++){
            dist[i][j] = 20000000;
        }
        dist[i][i] = 0;
    }

    int st,dt,w;
    for(int i = 0 ; i < m ; i++)
    {
        scanf("%d %d %d",&st, &dt, &w);

        adj[n].push_back({dt,w});
        //printf("c %d %d %d\n",st,dt,w);

        if(dist[st][dt] > w)
            dist[st][dt] = w;
    }

    for(int k = 1 ; k <= n ; k++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                int temp = dist[i][k] + dist[k][j];
                if(temp < dist[i][j])
                    dist[i][j] = temp;
            }
        }
    }

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(dist[i][j] == 20000000)
                printf("0 ");
            else
                printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
    
}