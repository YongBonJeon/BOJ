#include <bits/stdc++.h>
using namespace std;

int N,M;
char m[51][51];
int dp[51][51];
bool visited[51][51];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int dfs(int y, int x){
    if(y < 0 || x < 0 || y >= N || x >= M || m[y][x] == 'H')
        return 0;

    if(visited[y][x]){
        printf("-1\n");
        exit(0);
    }
    int &ret = dp[y][x];
    if(ret) return ret;

    visited[y][x] = 1;

    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i] * (m[y][x]-'0');
        int nx = x + dx[i] * (m[y][x]-'0');
        
        ret = max(ret,dfs(ny,nx)+1);
    }

    visited[y][x] = 0;
    return ret;
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0 ; i < N ; i++)
        scanf("%s",m[i]);
    
    printf("%d\n",dfs(0,0));

}