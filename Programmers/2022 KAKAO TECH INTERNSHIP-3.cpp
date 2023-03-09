#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int INF = 987654321;
// 현재 알고력, 코딩력, 
int dp[450][450];  

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int max_alp = alp, max_cop = cop;
    for(auto p : problems){
        max_alp = max(max_alp, p[0]);
        max_cop = max(max_cop, p[1]);
    }
    problems.push_back({0,0,0,1,1});
    problems.push_back({0,0,1,0,1});
    for(int i = alp ; i <= 151 ; i++){
        for(int j = cop ; j <= 151 ; j++){
            dp[i][j] = INF;
        }
    }
    dp[alp][cop] = 0;
    
    int nalp;
    int ncop;
    for(int i = alp ; i <= max_alp ; i++){
        for(int j = cop ; j <= max_cop ; j++){
            if(i == max_alp && j == max_cop) return dp[max_alp][max_cop];
            for(auto p : problems){
                if(p[0] > i || p[1] > j) continue;
                
                nalp = i + p[2];
                ncop = j + p[3];
                
                nalp = min(max_alp, nalp);
                ncop = min(max_cop, ncop);
                
                //cout << nalp << " " << ncop << '\n';
                
                dp[nalp][ncop] = min(dp[nalp][ncop], dp[i][j] + p[4]);
            }
        }
    }
    answer = dp[max_alp][max_cop];
    return answer;
}