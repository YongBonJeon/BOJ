#include <stdio.h>

#define MAX 501
#define select_max(a, b) (((a) > (b)) ? (a) : (b))

int dp[MAX][MAX];
int n;

int main(){
    scanf("%d",&n);

    int temp[MAX] = {0,};
    int sum = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i ; j++){
            scanf("%d", &temp[j]);

            if(i == 1){
                dp[1][1] = temp[j];
                sum = dp[1][1];
                continue;
            }

            
        }
        dp[i][1] = dp[i-1][1] + temp[1];
        if(sum < dp[i][1]){
            sum = dp[i][1];
        }
        dp[i][i] = dp[i-1][i-1] + temp[i];
        if(sum < dp[i][i]){
            sum = dp[i][i];
        }

        for(int j = 2 ; j  <  i ; j++){
            dp[i][j] = select_max(dp[i-1][j-1] + temp[j], dp[i-1][j] + temp[j]);
            if(sum < dp[i][j]){
                sum = dp[i][j];
            }
        }
    }
    printf("%d\n",sum);
}