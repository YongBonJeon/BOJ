#include <bits/stdc++.h>
using namespace std;

int R,C;
char m[21][21];
int visited[21][21];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int max_alpha = 0;
vector<int> path;

void go(int y, int x)
{
    int ny, nx;

    //visited[y][x] = 1;
    //printf("%d %d\n",y,x);

    if(max_alpha < path.size())
        max_alpha = path.size();

    for(int i = 0 ; i < 4 ; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= R || nx >= C)
            continue;

        if(!visited[ny][nx])
        {
            if(find(path.begin(), path.end() , m[ny][nx]) == path.end())
            {
                path.push_back(m[ny][nx]);
                visited[ny][nx] = 1;
                go(ny,nx);
                path.pop_back();
                visited[ny][nx] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d %d",&R,&C);

    for(int i = 0 ; i < R ; i++)
        scanf("%s",m[i]);

    memset(visited,0, sizeof(visited));
    visited[0][0] = 1;
    path.push_back(m[0][0]);
    go(0,0);

    printf("%d\n",max_alpha);
}