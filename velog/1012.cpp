#include <bits/stdc++.h>
using namespace std;

int N,M,K;
int m[51][51];
int visited[51][51];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void dfs(int y, int x)
{
    int ny, nx;

    visited[y][x] = 1;

    for(int i = 0 ; i < 4 ; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny < 0 || ny >= M || nx < 0 || nx >= N || !m[ny][nx])
            continue;
        
        if(!visited[ny][nx])
            dfs(ny, nx);
    }
}

int main()
{
    int num_TC;

    scanf("%d", &num_TC);

    for(int i = 0 ; i < num_TC ; i++)
    {
        int ans = 0;
        scanf("%d %d %d",&N, &M, &K);
        memset(m, 0, sizeof(m));
        memset(visited, 0, sizeof(visited));

        for(int j = 0 ; j < K ; j++)
        {
            int y,x;
            scanf("%d %d",&x, &y);
            m[y][x] = 1;
        }

        for(int p = 0 ; p < M ; p++)
        {
            for(int q = 0 ; q < N ; q++)
            {
                if(m[p][q] && !visited[p][q])
                {
                    dfs(p,q);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
}