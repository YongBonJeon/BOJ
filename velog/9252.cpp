#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main(){
    string A;
    string B;

    cin >> A >> B;
    int lenA = A.size();
    int lenB = B.size();

    for(int i = 1 ; i <= lenA ; i++){
        for(int j = 1 ; j <= lenB ; j++){
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    /*for(int i = 0 ; i <= lenA ; i++){
        for(int j = 0 ; j <= lenB ; j++)
            printf("%d ",dp[i][j]);
        printf("\n");
    }*/

    int y = lenA;
    int x = lenB;
    string ans;
    while(dp[y][x]){
        if(dp[y][x] == dp[y-1][x])
            y--;
        else if(dp[y][x] == dp[y][x-1])
            x--;
        else{
            ans += A[y-1];
            y--; x--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout << dp[lenA][lenB] << '\n' <<ans << '\n';

}

/* dp[i][j]



*/