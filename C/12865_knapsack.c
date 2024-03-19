#include <stdio.h>

#define select_max(a,b) (((a) > (b)) ? (a) : (b))

int n, k;
int dp[101][1000001] = {0,};
int w[101];
int v[101];

int main(){
    scanf("%d %d",&n, &k);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d %d",&w[i], &v[i]);
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= k ; j++){
            if(j - w[i] >= 0){
                dp[i][j] = select_max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("%d\n",dp[n][k]);

}