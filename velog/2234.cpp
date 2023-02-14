#include <bits/stdc++.h>
using namespace std;

int N,M;
int m[51][51][4];
int visited[51][51];
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};

int bfs(int y, int x)
{
    queue<pair<int, int>> q; 
    int ny,nx, area = 1;
    
    visited[y][x] = 1;
    q.push({y,x});

    while(!q.empty()){
        tie(y,x) = q.front(); q.pop();

        for(int i = 0 ; i < 4 ; i++)
        {
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= M || nx >= N || m[y][x][i] == 1)
                continue;
        
            if(!visited[ny][nx])
            {
                visited[ny][nx] = 1;
                q.push({ny,nx});
                area++;
            }
        }
    }
    return area;
}

int main()
{
    scanf("%d %d",&N,&M);

    memset(m,0,sizeof(m));
    int temp;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%d",&temp);
            
            for(int k = 0 ; k < 4 ; k++){
                if((temp & 1))
                    m[i][j][k] = 1;
                temp >>= 1;
            }
        }
    }

    memset(visited,0,sizeof(visited));
    int cnt = 0, max_ = 0;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(!visited[i][j]){
                max_ = max(max_, bfs(i,j));
                cnt++;
            }
        }
    }
    printf("%d\n%d\n",cnt,max_);

    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            for(int k = 0 ; k < 4 ; k++){
                if(m[i][j][k])
                {
                    memset(visited,0,sizeof(visited));
                    m[i][j][k] = 0;
                    max_ = max(max_, bfs(i,j));
                    m[i][j][k] = 1;
                }
            }
        }
    }
    printf("%d\n",max_);
}