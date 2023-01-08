#include <bits/stdc++.h>
using namespace std;

int M,N;
int m[101][101];
int visited[101][101];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int qwer = 0;
void dfs(int y, int x)
{
    int ny, nx;

    visited[y][x] = 1;
    qwer++;

    for(int i = 0 ; i < 4 ; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny < 0 || ny >= M || nx < 0 || nx >= N || m[ny][nx] < 0)
            continue;
        
        if(!visited[ny][nx])
            dfs(ny, nx);
    }
}

int main()
{
    int K;
    scanf("%d %d %d", &M, &N, &K);

    memset(m,0,sizeof(m));

    for(int i = 0 ; i < K ; i++)
    {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

        for(int j = y1 ; j < y2 ; j++)
            for(int k = x1 ; k < x2 ; k++)
                m[j][k]--;
    }

    /*for(int i = 0 ; i < M ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }*/

    vector<int> ans;
    for(int i = 0 ; i < M ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            if(!visited[i][j] && m[i][j] >= 0)
            {
                qwer = 0;
                dfs(i,j);
                ans.push_back(qwer);
            }
        }
    }
    sort(ans.begin(),ans.end());
    printf("%zd\n",ans.size());
    for(int i = 0 ; i < ans.size() ; i++)
        printf("%d ",ans[i]);
    printf("\n");
    
    

}