#include <bits/stdc++.h>
using namespace std;

int N,M;
int visited[101][101];
int m[101][101];
int dy[4] = { -1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};

void bfs()
{
    queue<pair<int, int>> q;
    int y, x, ny, nx;
    
    visited[0][0] = 1;
    q.push({0,0});

    while(q.size())
    {
        tie(y, x) = q.front(); q.pop();

        //printf("%d %d\n", y, x);

        for(int i = 0 ; i < 4 ; i++)
        {
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M || m[ny][nx] == 0 || visited[ny][nx] != 0)
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main()
{
    scanf("%d %d",&N, &M);

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            scanf("%1d", &m[i][j]);
        }
    }

    bfs();

    printf("%d\n",visited[N-1][M-1]);
}

