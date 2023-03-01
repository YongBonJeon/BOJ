#include <bits/stdc++.h>
using namespace std;

int n;
int hp[21];
int happy[21];
int dp[101];

int main(){
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d",&hp[i]);
    for(int i = 0 ; i < n ; i++)
        scanf("%d",&happy[i]);
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 99 ; j >= hp[i] ; j--){
            dp[j] = max(dp[j],dp[j-hp[i]]+happy[i]);
        }
    }
    
    printf("%d\n",dp[99]);
}