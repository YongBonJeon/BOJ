#include <stdio.h>

#define Min(a,b) (((a) < (b)) ? (a) : (b))

int dp[1001][3];
int n;

int main(){
    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        int temp[3];
        scanf("%d %d %d", &temp[0], &temp[1], &temp[2]);

        if(i == 1){
            dp[1][0] = temp[0];
            dp[1][1] = temp[1];
            dp[1][2] = temp[2];
            continue;
        }

        dp[i][0] = temp[0] + Min(dp[i-1][1], dp[i-1][2]);
        //printf("%d %d\n\n",temp[0], Min(dp[i-1][1], dp[i-1][2]));
        dp[i][1] = temp[1] + Min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = temp[2] + Min(dp[i-1][0], dp[i-1][1]);
        //printf("%d %d %d\n", dp[i][0], dp[i][1], dp[i][2]);
    }

    printf("%d\n", Min(Min(dp[n][0], dp[n][1]), dp[n][2]));

}