#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int INF = 98765321;
int dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    
    for(auto x : fares) {
        dist[x[0]][x[1]] = x[2];
        dist[x[1]][x[0]] = x[2];
    }
    
    for(int k = 1 ; k <= n ; k++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                int temp = dist[i][k] + dist[k][j];
                if(temp < dist[i][j])
                    dist[i][j] = temp;
            }
        }
    }
    
    answer = INF;
    for(int i = 1 ; i <= n ; i++) {
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return answer;
}