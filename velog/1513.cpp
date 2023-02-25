#include <bits/stdc++.h>
using namespace std;

const int p = 1000007;

int N,M,C;
// N/ M /방문수 /마지막 방문 오락실
int m[51][51];
int dp[51][51][51][51];

int main(){
    scanf("%d %d %d",&N, &M, &C);
    int y,x,o;
    for(int i = 1 ; i <= C ; i++){
        scanf("%d %d",&y,&x);

        m[y][x] = i;
    }

    memset(dp,0,sizeof(dp));

    if((o = m[1][1]))
        dp[1][1][1][o] = 1;
    else
        dp[1][1][0][0] = 1;

    // N/ M /방문수 /마지막 방문 오락실
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            if(i == 1 && j == 1)
                continue;
            if((o = m[i][j])){
                // 증가하는 순서대로 오락실 방문 
                for(int l = 0 ; l < o ; l++){
                    for(int k = 0 ; k <= l ; k++){
                        dp[i][j][k+1][o] += dp[i-1][j][k][l] + dp[i][j-1][k][l];
                        dp[i][j][k+1][o] %= p;
                    }
                }
            }
            else{
                // 오락실이 아니므로 이동
                for(int l = 0 ; l <= C ; l++){
                    for(int k = 0 ; k <= l ; k++){
                        dp[i][j][k][l] += dp[i-1][j][k][l] + dp[i][j-1][k][l];
                        dp[i][j][k][l] %= p;
                    }
                }
            }
        }
    }


    /*for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            if(i+1 <= N && (o = m[i+1][j])){
                // 증가하는 순서대로 오락실 방문 
                for(int k = 1 ; k <= o ; k++)
                    for(int l = 0 ; l <= o-1 ; o++)
                        dp[i+1][j][k][o] += dp[i][j][k-1][l];
            }
            else if(i+1 <= N){
                for(int o = 0 ; o <= C ; o++)
                    for(int k = 0 ; k <= o ; k++)
                        dp[i+1][j][k][o] += dp[i][j][k][o];
            }
            if(j+1 <= M && (o = m[i][j+1])){
                // 증가하는 순서대로 오락실 방문 
                for(int k = 1 ; k <= o ; k++)
                    for(int l = 0 ; l <= o-1 ; o++)
                        dp[i][j+1][k][o] += dp[i][j][k-1][l];
            }
            else if(j+1 <= M){
                for(int o = 0 ; o <= C ; o++)
                    for(int k = 0 ; k <= o ; k++)
                        dp[i][j+1][k][o] += dp[i][j][k][o];
            }
            
        }
    }*/

    for(int i = 0 ; i <= C ; i++){
        int sum = 0;
        for(int j = 0 ; j <= C ; j++)
            sum += dp[N][M][i][j];
        printf("%d ",sum%p);
    }
    printf("\n");
}