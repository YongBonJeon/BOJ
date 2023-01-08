#include<bits/stdc++.h>
using namespace std;

int N, max_height = 0;
int m[101][101];
int visited[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x,int height)
{
    int ny, nx;

    visited[y][x] = 1;

    for(int i = 0 ; i < 4 ; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= N || m[ny][nx] <= height)
            continue;
        
        if(!visited[ny][nx])
            dfs(ny, nx, height);
    }
}

int main()
{
    scanf("%d", &N);

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++){
            scanf("%d",&m[i][j]);
            if(m[i][j] > max_height)
                max_height = m[i][j];
        }
    //printf("h %d\n",max_height);
    int max_component = 0;
    for(int i = 0 ; i < max_height ; i++)
    {
        int temp = 0;
        memset(visited, 0, sizeof(visited));

        for(int j = 0 ; j < N ; j++)
        {
            for(int k = 0 ; k < N ; k++)
            {
                if(!visited[j][k] && m[j][k] > i)
                {
                    //printf("%d %d %d\n",i,j,k);
                    dfs(j,k, i);
                    temp++;
                }
            }
        }
        if(temp > max_component)
            max_component = temp;
    }
    printf("%d\n",max_component);
}