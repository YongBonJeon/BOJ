#include <bits/stdc++.h>
using namespace std;

int N,M;
int ladder[101];
int snake[101];
int dp[101];

int main(){
    scanf("%d %d",&N, &M);

    int st,dt;
    for(int i = 0 ; i < N ; i++){
        scanf("%d %d",&st, &dt);
        ladder[st] = dt;
    }
    for(int i = 0 ; i < M ; i++){
        scanf("%d %d",&st, &dt);
        snake[st] = dt;
    }
    for(int i = 0 ; i <= 100 ; i++)
        dp[i] = 987654321;

    queue<int> q;
    int cur,next;

    // 시작
    dp[1] = 0; q.push(1);

    while(!q.empty()){
        cur = q.front(); q.pop();
        //printf("cur %d\n",cur);
        for(int dice = 1 ; dice <= 6 ; dice++){
            next = cur+dice;
            if(next > 100) continue;
            if(ladder[next] != 0) next = ladder[next];
            if(snake[next] != 0) next = snake[next];

            if(dp[next] > dp[cur] + 1){
                dp[next] = dp[cur] + 1;
                q.push(next);
            }
        }
    }

    printf("%d\n",dp[100]);
}