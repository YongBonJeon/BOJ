#include <bits/stdc++.h>
using namespace std;

/*int N;
int m[20][20];
int dp[16][1<<16];
int min_ = 987654321;

int tsp(int cur, int visited)
{
    int &ret = dp[cur][visited];
    if(ret != -1){
        return ret;
    }

    // 모든 vertex 방문 ? 
    if(visited == (1<<N)-1){
        if(m[cur][0] != 0){
            return m[cur][0];
        }
        return 987654321;
    }

    ret = 987654321;
    for(int i = 0 ; i < N ; ++i){
        // 이미 방문 or cur -> i 로 길이 존재하지 않음
        if((visited & (1<<i)) == 1 << i || m[cur][i] == 0)
            continue;
        ret = min(ret, tsp(i,visited|(1<<i)) + m[cur][i]);
    }
    
    return ret;
}

int main()
{
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            scanf("%d",&m[i][j]);
    
    memset(dp,-1,sizeof(dp));
    printf("%d\n",tsp(0,1));

    
}*/


int INF = 987654321;
int N;
int W[16][16];
int dp[16][1 << 16];

int dfs(int v, int visit){
    int &ret = dp[v][visit];

    // 전부 방문 했을 때
    if(visit == (1 << N)-1){
        if(W[v][0])
            return W[v][0];
        else
            return INF;
    }


    if(ret != -1)
        return ret;

    ret = INF;
    for(int dt = 0 ; dt < N ; dt++){
        // dt를 방문하지 않았고 가는 길이 존재할 때 
        if((visit & (1 << dt)) == 0 && W[v][dt] > 0){
            ret = min(ret, dfs(dt, (visit | (1 << dt))) + W[v][dt]);
        }
    }

    return ret;
}

int main(){
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%d",&W[i][j]);
        }
    }
    //fill(dp,dp+sizeof(dp),INT_MAX);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",dfs(0,1));
}