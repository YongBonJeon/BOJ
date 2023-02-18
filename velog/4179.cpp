#include <bits/stdc++.h>
using namespace std;

int R,C;
int success = 0, min_dist = INT_MAX;
char m[1001][1001];
int visited[1001][1001];
int fire[1001][1001];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
queue<pair<int,int>> q_fire;

void fire_spread()
{
    int ny,nx, y, x;

    while(!q_fire.empty())
    {
        tie(y,x) = q_fire.front(); q_fire.pop();

        for(int i = 0 ; i < 4 ; i++)
        {
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= R || nx >= C || m[ny][nx] == '#')
                continue;

            if(!fire[ny][nx])
            {
                fire[ny][nx] = fire[y][x] + 1;
                q_fire.push({ny,nx});
            }
        }
    }

}

int move(int y, int x)
{
    queue<pair<int,int>> q;
    int ny,nx;

    q.push({y,x});

    while(!q.empty())
    {
        tie(y,x) = q.front(); q.pop();

        if(y == 0 || x == 0 || y == R-1 || x == C-1)
        {
            return visited[y][x];
        }

        for(int i = 0 ; i < 4 ; i++)
        {
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= R || nx >= C || m[ny][nx] == '#')
                continue;

            if(!visited[ny][nx])
            {
                visited[ny][nx] = visited[y][x] + 1;
                if(visited[ny][nx] < fire[ny][nx])
                    q.push({ny,nx});
                
            }
        }
    }
       
    return false;
}

void fire_zero()
{
    for(int i = 0 ; i < R ; i++)
        for(int j = 0 ; j < C ; j++)
            fire[i][j] = INT_MAX;
}
int main()
{
    int cur_y, cur_x;
    scanf("%d %d",&R,&C);

    for(int i = 0 ; i < R ; i++)
    {
        scanf("%s",m[i]);
    }

    memset(fire,0,sizeof(fire));
    memset(visited,0,sizeof(visited));
    
    for(int i = 0 ; i < R ; i++)
    {
        for(int j = 0 ; j < C ; j++)
        {
            if(m[i][j] == 'F'){
                q_fire.push({i,j});
                fire[i][j] = 1;
            }
            else if(m[i][j] == 'J'){
                cur_y = i; cur_x = j;
            }
        }
    }

    if(!q_fire.empty())
        fire_spread();
    else
        fire_zero();
    
    visited[cur_y][cur_x] = 1;
    if((min_dist = move(cur_y, cur_x)))
        printf("%d\n",min_dist);
    else
        printf("IMPOSSIBLE\n");
    
}