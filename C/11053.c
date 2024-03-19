#include <stdio.h>

int input[1001] = {0,};
int dp[1001] = {0,};

int main(){
    int n;

    scanf("%d",&n);
    
    int dpmax = 1;
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&input[i]);

        dp[i] = 1; // 기본값

        int temp_max = 0;
        for(int j = 0 ; j < i ; j++){
            /* 자기보다 작은 값들을 서치 */
            if(input[i] > input[j]){
                if(temp_max < dp[j]){
                    temp_max = dp[j];
                }
            }
        }
        dp[i] = temp_max + 1;

        if(dpmax < dp[i]){
            dpmax = dp[i];
        }
    }
    printf("%d\n",dpmax);
}