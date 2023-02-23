#include <bits/stdc++.h>
using namespace std;

typedef struct _pipe{
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
    /*for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++)
            printf("%d ",dp[i][j][0]);
        printf("\n");
    }
    printf("\n");
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++)
            printf("%d ",dp[i][j][1]);
        printf("\n");
    }
    printf("\n");
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++)
            printf("%d ",dp[i][j][2]);
        printf("\n");
    }*/

    printf("%d\n",dp[N][N][0]+dp[N][N][1]+dp[N][N][2]);
}