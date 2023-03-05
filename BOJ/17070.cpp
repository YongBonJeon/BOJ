#include <bits/stdc++.h>
using namespace std;

/*typedef struct _pipe{
    int y;
    int x;
    int state;
}pipe;

int N;
int m[20][20];
int dp[20][20][3];

bool check(int y, int x, int dir){
    if(dir == 0 || dir == 2){
        if(m[y][x])
            return false;
    }
    else if(dir == 1){
        if(m[y][x] || m[y-1][x] || m[y][x-1])
            return false;
    }
    return true;
}

int main(){
    scanf("%d",&N);
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            scanf("%d",&m[i][j]);
    
    dp[1][2][0] = 1;

    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            if(check(i,j+1,0))
                dp[i][j+1][0] += dp[i][j][0];      
            if(check(i+1,j+1,1))
                dp[i+1][j+1][1] += dp[i][j][0];
            if(check(i+1,j,2))
                dp[i+1][j][2] += dp[i][j][2];
            if(check(i+1,j+1,1))
                dp[i+1][j+1][1] += dp[i][j][2];
            if(check(i,j+1,0))
                dp[i][j+1][0] += dp[i][j][1];
            if(check(i+1,j,2))
                dp[i+1][j][2] += dp[i][j][1];
            if(check(i+1,j+1,1))
                dp[i+1][j+1][1] += dp[i][j][1];
        }
    }
    printf("%d\n",dp[N][N][0]+dp[N][N][1]+dp[N][N][2]);
}*/

int N;
int M[16][16];
int dp[16][16][3];

int dfs(int y, int x, int dir){
    int &ret = dp[y][x][dir];
    if(y == N-1 && x == N-1)
        return 1;

    if(ret)
        return ret;

    if(dir == 1){
        if(x+1 < N && !M[y][x+1])
            ret += dfs(y,x+1,1);
        if(y+1 < N && x+1 < N && !M[y][x+1] && !M[y+1][x] && !M[y+1][x+1])
            ret += dfs(y+1,x+1,2);
    }
    else if(dir == 2){
        if(x+1 < N && !M[y][x+1])
            ret += dfs(y,x+1,1);
        if(y+1 < N && !M[y+1][x])
            ret += dfs(y+1,x,3);
        if(y+1 < N && x+1 < N && !M[y][x+1] && !M[y+1][x] && !M[y+1][x+1])
            ret += dfs(y+1,x+1,2);
    }
    else if(dir == 3){
        if(y+1 < N && !M[y+1][x])
            ret += dfs(y+1,x,3);
        if(y+1 < N && x+1 < N && !M[y][x+1] && !M[y+1][x] && !M[y+1][x+1])
            ret += dfs(y+1,x+1,2);
    }

    return ret;
}

int main(){
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%d",&M[i][j]);
        }
    }

    memset(dp,0,sizeof(dp));
    printf("%d\n",dfs(0,1,1));

}