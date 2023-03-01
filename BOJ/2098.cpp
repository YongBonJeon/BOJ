#include <bits/stdc++.h>
using namespace std;

int N;
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

    
}