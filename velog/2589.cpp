#include <bits/stdc++.h>
using namespace std;

int N,M;
char m[51][51];
int visited[51][51];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int bfs(int y0, int x0)
{
    queue<pair<int,int>> q;
    int y,x,ny,nx, max_dist = 0;

    visited[y0][x0] = 1;
    q.push({y0,x0});

    while(!q.empty())
    {
        tie(y,x) = q.front(); q.pop();
        if(visited[y][x] > max_dist)
            max_dist = visited[y][x];

        for(int i = 0 ; i < 4 ; i++)
        {
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= N || nx >= M || m[ny][nx] == 'W')
                continue;

            if(!visited[ny][nx])
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            }
       }
    }
    return max_dist;
}

int main()
{
    int total_max = 0, temp;
    scanf("%d %d",&N,&M);

    for(int i = 0 ; i < N ; i++)
        scanf("%s",m[i]);

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            if(m[i][j] == 'L'){
                memset(visited,0,sizeof(visited));
                if((temp = bfs(i,j)) > total_max)
                    total_max = temp;
                //printf("%d\n",bfs(i,j));
            }
        }
    }

    printf("%d\n",total_max-1);
}