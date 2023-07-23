#include <bits/stdc++.h>
using namespace std;

int cur_row[3];
int min_dp[2][3];
int max_dp[2][3];
int N;

int main(){
    scanf("%d",&N);

    for(int j = 0 ; j < 3 ; j++){
        scanf("%1d",&cur_row[j]);
    }

    min_dp[0][0] = cur_row[0];
    min_dp[0][1] = cur_row[1];
    min_dp[0][2] = cur_row[2];
    
    max_dp[0][0] = cur_row[0];
    max_dp[0][1] = cur_row[1];
    max_dp[0][2] = cur_row[2];

    for(int i = 1 ; i < N ; i++){
        for(int j = 0 ; j < 3 ; j++){
            scanf("%1d",&cur_row[j]);
        }

        min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + cur_row[0];
        min_dp[1][1] = min(min(min_dp[0][0], min_dp[0][1]),min_dp[0][2]) + cur_row[1];
        min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + cur_row[2];

        max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + cur_row[0];
        max_dp[1][1] = max(max(max_dp[0][0], max_dp[0][1]),max_dp[0][2]) + cur_row[1];
        max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + cur_row[2];

        for(int j = 0 ; j < 3 ; j++){
            min_dp[0][j] = min_dp[1][j];
            max_dp[0][j] = max_dp[1][j];
        }
    }
    

    printf("%d ",max(max(max_dp[0][0],max_dp[0][1]),max_dp[0][2]));
    printf("%d\n",min(min(min_dp[0][0],min_dp[0][1]),min_dp[0][2]));

}