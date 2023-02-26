#include <bits/stdc++.h>
using namespace std;

int N,M;
string seq;
int dp[2505][2505];

int main(){
    cin >> seq;

    N = seq.size();
    for(int i = 0 ; i < N ; i++){
        dp[i][i] = 1;
        if(i != N-1 && seq[i] == seq[i+1])
            dp[i][i+1] = 1;
    }

    for(int i = N-1 ; i > 0 ; i--){
        for(int j = 0 ; j < N-1 ; j++){
            if(dp[i][j] && seq[i-1] == seq[j+1]){
                dp[i-1][j+1] = 1;
            }   
        }
    }

    /*for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++)
            printf("%d ",dp[i][j]);
        printf("\n");
    }*/

    int dp2[2505];
    for(int i = 0 ; i <= N ; i++)
        dp2[i] = INT_MAX;
    dp2[0] = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = i ; j < N ; j++){
            if(dp[i][j]){
                dp2[j+1] = min(dp2[j+1],dp2[i] + 1);
                //printf("%d %d %d\n",i,j,dp2[j+1]);
            }
        }
    }
    printf("%d\n",dp2[N]);
    /*for(int i = 0 ; i <= N ; i++)
        printf("%d ",dp2[i]);
    printf("\n");*/


    /*int cur = 0, ans = 0;
    while(cur != N){
        int i;
        for(i = N-1 ; i > cur ; i--){
            if(dp[cur][i]){
                printf("%d %d\n",cur,i);
                ans++;
                cur = i+1;
                
                break;
            }
        }
        if(cur == i){
            printf("%d\n",cur);
            ans++;
            cur++;
        }
    }
    printf("%d\n",ans);*/
}