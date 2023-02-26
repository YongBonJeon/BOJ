#include <bits/stdc++.h>
using namespace std;

double a,b,pa,pb;
// 간격 / a득점 / b득점
double dp[20][20][20];

/*
모든 팀이 합성수or0,1 득점
0,1,4,6,8,9,10,12,14,15,16,18 
dp[0][0]
dp[0][1]
dp[0][4]
dp[4][14]
dp[6][12]
dp[8][10]
dp[9][9]
*/

int main(){
    scanf("%lf %lf",&a, &b);
    pa = a/100;
    pb = b/100;

    // dp[i][j] <- dp[i-1][j] ,dp[i][j-1]
    dp[0][0][0] = 1.0;

    for(int idx = 1 ; idx <= 18 ; idx++){
        for(int i = 0 ; i <= idx ; i++){
            for(int j = 0 ; j <= idx ; j++){
                if(i > 0)
                    dp[idx][i][j] += dp[idx-1][i-1][j]*pa*(1-pb);
                if(j > 0)
                    dp[idx][i][j] += dp[idx-1][i][j-1]*(1-pa)*pb;
                if(i > 0 && j > 0)
                    dp[idx][i][j] += dp[idx-1][i-1][j-1]*pa*pb;
                dp[idx][i][j] += dp[idx-1][i][j]*(1-pa)*(1-pb);
            }
        }
    }

    // 적어도 한 팀이 소수로 득점할 확률 = 전체화률 - 모든 팀이 합성수or0,1로 득점할 확률
    //0,1,4,6,8,9,10,12,14,15,16,18
    int x[12] = {0,1,4,6,8,9,10,12,14,15,16,18};
    double sum = 0.0;
    
    for(int i = 0 ; i < 12 ; i++){
        for(int j = 0 ; j < 12 ; j++){
            sum += dp[18][x[i]][x[j]];
        }
    }
    printf("%.9lf\n",1.0-sum);

}