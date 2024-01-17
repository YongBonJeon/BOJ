#include <bits/stdc++.h>
using namespace std;

int N,M,C;
int jewel[14];
// cur / 
int dp[24][1 << 14][24];

int dfs(int cur,int capacity, int visit){
    if(cur == M) return 0;
    
    int& ret = dp[cur][visit][capacity];
    if(ret) return ret;

    for(int i = 0 ; i < N ; i++){
        if((visit & (1 << i)) == 0 && capacity-jewel[i] >= 0){
            ret = max(ret,dfs(cur, capacity-jewel[i],visit | (1 << i)) + 1);
        }
    }
    ret = max(ret, dfs(cur+1, C, visit));
    

    return ret;
}

int main(){
    scanf("%d %d %d",&N, &M, &C);
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&jewel[i]);

    memset(dp,0,sizeof(dp));
    printf("%d\n",dfs(0,C,0));

}