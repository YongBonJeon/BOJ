#include <bits/stdc++.h>
using namespace std;

int N,M;
int x2,y2,x3,y3;
char m[301][301];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited[301][301];

int bfs(int y, int x)
{
    queue<pair<int, int>> q;
    int ny,nx;

    visited[y][x] = 1;

    q.push({y,x});

    while(!q.empty())
    {
        tie(y,x) = q.front(); q.pop();

        for(int i = 0 ; i < 4 ; i++)
        {
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;

            if(m[ny][nx] == '#'){
                visited[ny][nx] = visited[y][x] + 1;
                return 1;
            }

            if(m[ny][nx] == '1')
            {
                m[ny][nx] = '0';
                visited[ny][nx] = visited[y][x] + 1;
                continue;
            }

            if(!visited[ny][nx] && m[ny][nx] == '0')
            {
                q.push({ny,nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d",&N, &M);
    scanf("%d %d %d %d",&y2,&x2,&y3,&x3);

    for(int i = 0 ; i < N ; i++)
        scanf("%s",m[i]);

    int ans = 1;
    while(!bfs(y2-1,x2-1))
    {
        ans++;
        memset(visited, 0 , sizeof(visited));
    }
    printf("%d\n",ans);


}