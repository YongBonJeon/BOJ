#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

int dp[MAX];
int track[MAX];
int temp;


int main(){
    int N;

    scanf("%d",&N);

    for(int i = 0 ; i <= N ; i++)
        dp[i] = INT_MAX;
    dp[1] = 0;

    for(int i = 1 ; i < N ; i++){
        if(i*3 < MAX && dp[i*3] > dp[i] + 1){
            dp[i*3] = dp[i] + 1;
            track[i*3] = i;
        }
        if(i*2 < MAX && dp[i*2] > dp[i] + 1){
            dp[i*2] = dp[i] + 1;
            track[i*2] = i;
        }
        if(i+1 < MAX && dp[i+1] > dp[i] + 1){
            dp[i+1] = dp[i] + 1;
            track[i+1] = i;
        }
    }
    printf("%d\n",dp[N]);
    /*for(int i = 1 ; i <= N ; i++)
        printf("%d ",track[i]);
    printf("\n");*/
    
    int t = N;
    while(t != 1){
        printf("%d ",t);
        t = track[t];
    }
    printf("1\n");
}