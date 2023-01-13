#include <bits/stdc++.h>
using namespace std;

int N,M;
int m[100][100];
int test[100][100];
int visited[100][100];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

bool dfs(int y, int x)
{
    //printf("%d %d\n",y, x);
    int ny, nx, ret;

    if(y == 0 || x == 0 || y == N-1 || x == M-1)
        return true;

    visited[y][x] = 1;

    for(int i = 0 ; i < 4 ; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];

        //printf("ny nx %d %d\n",ny,nx);
        if(ny < 0 || nx < 0 || ny >= N || nx >= M || m[ny][nx] == 1)
            continue;
        
        if(!visited[ny][nx])
            ret =  dfs(ny, nx);
    }
    return ret;
}

int main()
{
    scanf("%d %d",&N,&M);

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            scanf("%d",&m[i][j]);

    memset(test, 0, sizeof(test));

    int time = 0;
    int ans = 0;
    while(1)
    {
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < M ; j++)
                if(test[i][j] == 1)
                    m[i][j] = 0;

        memset(test,0,sizeof(test));
        int flag = 0;
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < M ; j++)
                if(m[i][j] == 1)
                    flag = 1;

        if(!flag)
            break;

        ans = 0;
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M ; j++)
            {
                if(m[i][j] == 1)
                {
                    //printf("dfs %d %d\n",i,j);
                    memset(visited, 0, sizeof(visited));
                    int res = dfs(i,j);
                    //printf("\n");
                    if(res){
                        test[i][j] = 1;
                        ans++;
                    }
                }
            }
        }
        /*printf("\n");
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M ; j++)
            {
                printf("%d ",test[i][j]);
            }
            printf("\n");
        }*/

        time++;
        //break;
    }

    printf("%d\n%d\n",time,ans);
}