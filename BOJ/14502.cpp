#include <bits/stdc++.h>
using namespace std;

int N,M, area1;
int m[9][9];
int wall[65][65][65];
int visited[9][9];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int dfs(int y, int x)
{
    int ny,nx;
    int ret = 1;
    visited[y][x] = 1;

    for(int i = 0 ; i < 4 ; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= M || nx >= N || m[ny][nx] != 0)
            continue;

        if(!visited[ny][nx])
            ret += dfs(ny,nx);
    }
    return ret;
}

int solve(pair<int, int> wall_1, pair<int, int> wall_2, pair<int, int> wall_3)
{
    memset(visited, 0, sizeof(visited));
    if((wall_1 == wall_2) || (wall_2 == wall_3))
        return 0;
    
    if(m[wall_1.first][wall_1.second] != 0 || m[wall_2.first][wall_2.second] != 0 || m[wall_3.first][wall_3.second] != 0)
        return 0;

    m[wall_1.first][wall_1.second] = 1;
    m[wall_2.first][wall_2.second] = 1;
    m[wall_3.first][wall_3.second] = 1;

    int ans = 0;

    for(int i = 0 ; i < M ; i++)
        for(int j = 0 ; j < N ; j++)
            if(m[i][j] == 2)
                ans += dfs(i,j);

    m[wall_1.first][wall_1.second] = 0;
    m[wall_2.first][wall_2.second] = 0;
    m[wall_3.first][wall_3.second] = 0;

    return M*N-ans-3;
}


int main()
{
    scanf("%d %d",&M,&N);

    for(int i = 0 ; i < M ; i++)
        for(int j = 0 ; j < N ; j++){
            scanf("%d",&m[i][j]);
            if(m[i][j] == 1)
                area1++;
        }
    int t1,t2,t3,t4,t5,t6;
    pair<int,int> wall_1, wall_2, wall_3;
    int max = 0;
    for(int i = 0 ; i < M ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            wall_1 = {i,j};

            for(int k = 0 ; k < M ; k++)
            {
                for(int l = 0 ; l < N ; l++)
                {
                    wall_2 = {k,l};

                    for(int m = 0 ; m < M ; m++)
                    {
                        for(int n = 0 ; n < N ; n++)
                        {
                            wall_3 = {m,n};
                            int temp = solve(wall_1, wall_2, wall_3);
                            if(max < temp){

                                max = temp;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",max-area1);
}