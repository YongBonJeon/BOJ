#include <bits/stdc++.h>
using namespace std;

int T,W,num;
int dp[1024][2][33];
int tnum[1024];

int dfs(int t, int num, int w){
    if(t == T)
        return 0;

    int& ret = dp[t][num][w];
    if(ret != -1) return ret;
    
    if(tnum[t] == num){
        if(w < W)
            ret = max(dfs(t+1,num,w)+1, dfs(t+1,3-num,w+1));
        else
            ret = dfs(t+1,num,w)+1;
    }
    else{
        if(w < W)
            ret = max(dfs(t+1,num,w),dfs(t+1,3-num,w+1)+1);
        else
            ret = dfs(t+1,num,w);
    }
    //printf("%d %d %d %d\n",t,num,w,ret);
    return ret; 
}

int main(){
    scanf("%d %d",&T, &W);
    
    for(int i = 0 ; i < T ; i++)
        scanf("%d",&tnum[i]);
    
    memset(dp,-1,sizeof(dp));
    printf("%d\n",dfs(0,1,0));

}