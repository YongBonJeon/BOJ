#include <bits/stdc++.h>
using namespace std;

int R,C,K,ans=0;
char m[5][5];
int visited[5][5];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void gohome(int y, int x, vector<pair<int,int>> ans1)
{
    int ny, nx;

    if(y == 0 && x == C-1){
        if(K == visited[y][x]){
            /*for(int i = 0 ; i < ans1.size() ; i++)
                printf("%d %d | ",ans1[i].first,ans1[i].second);
            printf("\n");*/
            ans++;
        }
        return ;
    }

    for(int i = 0 ; i < 4 ; i++)
    {
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= R || nx >= C || m[ny][nx] == 'T')
            continue;

        if(visited[ny][nx] == 0)
        {
            visited[ny][nx] = visited[y][x] + 1;
            ans1.push_back({ny,nx});
            gohome(ny,nx, ans1);
            ans1.pop_back();
            visited[ny][nx] = 0;
        }
    }

}

int main()
{
    scanf("%d %d %d",&R, &C, &K);

    for(int i = 0 ; i < R ; i++)
            scanf("%s",m[i]);

    memset(visited, 0, sizeof(visited));
    vector<pair<int,int>> ans1;
    visited[R-1][0] = 1;
    gohome(R-1, 0, ans1);

    printf("%d\n",ans);
}