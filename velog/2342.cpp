#include <bits/stdc++.h>
using namespace std;

int N;
int cmd[100001];

// 동작수 / 왼발 / 오른발
int dp[100001][5][5];

int go(int idx, int left, int right){
    if(cmd[idx] == 0)
        return 0;
    int& ret = dp[idx][left][right];
    if(ret != INT_MAX)
        return ret;

    // 이동 x
    if(left == cmd[idx] || right == cmd[idx]){
        ret = min(ret, go(idx+1, left, right)+1);
        return ret;
    }   

    // 왼발 이동 
    // 중앙에서 이동 
    if(left == 0)
        ret = min(ret, go(idx+1,cmd[idx],right)+2);
    else if(left != 0){
        // 반대 방향 이동
        if((left - cmd[idx])%2 == 0){
            ret = min(ret, go(idx+1,cmd[idx],right)+4);
        }
        else{
            ret = min(ret, go(idx+1,cmd[idx],right)+3);
        }
    }

    // 오른발 이동
    if(right == 0)
        ret = min(ret, go(idx+1,left,cmd[idx])+2);
    else if(left != 0){
        // 반대 방향 이동
        if((right - cmd[idx])%2 == 0){
            ret = min(ret, go(idx+1,left,cmd[idx])+4);
        }
        else{
            ret = min(ret, go(idx+1,left,cmd[idx])+3);
        }
    }
    return ret;
}


int main(){

    int t = -1,N = 0;
    while(t != 0){
        scanf("%d",&t);
        cmd[N++] = t;
    }
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < 5 ; j++)
            for(int k = 0 ; k < 5 ; k++)
                dp[i][j][k] = INT_MAX;
    
    printf("%d\n",go(0,0,0));

}

/*
dp[0][0][0] = 1;
dp[1][0][1] = 1;

*/