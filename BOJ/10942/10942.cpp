#include <bits/stdc++.h>
using namespace std;

int N,M,S,E;
int seq[2001];
pair<int,int> cmd[1000001];
int dp[2001][2001];

int main(){
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d",&seq[i]);
    //dp[i][i] = true
    //dp[i][i+1] = true?
    //dp[i][j] = true , seq[i-1] == seq[j+1] -> dp[i-1][j+1] = true 

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
        for(int j = 0 ; j < N ; j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    scanf("%d",&M);
    for(int i = 0 ; i < M ; i++){
        scanf("%d %d",&S,&E);
        if(dp[S-1][E-1])
            printf("1\n");
        else
            printf("0\n");
    }



}