#include <stdio.h>

#define select_max(a,b) (((a) > (b)) ? (a) : (b))

int sticker[2][100001] = {0,};
int dp[3][100002]={0,};

int main(){
    int num_test;

    scanf("%d",&num_test);

    while(num_test > 0){
        int n;

        scanf("%d ",&n);

        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < n ; j++){
                scanf("%d",&sticker[i][j]);
            }
        }
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j <= n+1 ; j++){
                dp[i][j] = 0;
            }
        }
        dp[1][1] = sticker[0][0];
        dp[2][1] = sticker[1][0];
        dp[0][2] = select_max(dp[1][1], dp[2][1]);

        for(int i = 2 ; i <= n ; i++){
            dp[1][i] = select_max(sticker[0][i-1] + dp[2][i-1], dp[0][i-1] + sticker[0][i-1]);
            dp[2][i] = select_max(sticker[1][i-1] + dp[1][i-1], dp[0][i-1] + sticker[1][i-1]);
            dp[0][i+1] = select_max(dp[1][i], dp[2][i]);
        }

        /*for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j <= n+1 ; j++){
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }*/
        printf("%d\n",dp[0][n+1]);
        num_test--;
    }
}