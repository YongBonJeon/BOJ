#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> variation(n+1, vector<int>(m+1));
    
    for(auto s : skill){
        int value = (s[0] == 1) ? -s[5] : s[5];
        variation[s[1]][s[2]] += value;
        variation[s[1]][s[4]+1] -= value;
        variation[s[3]+1][s[2]] -= value;
        variation[s[3]+1][s[4]+1] += value;
    }
    // variation 배열 각 행 별 누적합
    for(int i = 0 ; i < n+1 ; i++){
        int sum = 0;
        for(int j = 0 ; j < m+1 ; j++){
            sum += variation[i][j];
            variation[i][j] = sum;
        }
    }
    // variation 배열 각 열 별 누적합
    for(int j = 0 ; j < m+1 ; j++){
        int sum = 0;
        for(int i = 0 ; i < n+1 ; i++){
            sum += variation[i][j];
            variation[i][j] = sum;
        }
    }
    answer = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            board[i][j] += variation[i][j];
            
            if(board[i][j] > 0){   
                answer+=1;
            }
        }
    }
    
    return answer;
}


/*int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    for(auto s : skill){
        for(int i = s[1] ; i <= s[3] ; i++){
            for(int j = s[2] ; j <= s[4] ; j++){
                if(s[0] == 1){
                    board[i][j] -= s[5];
                }
                else if(s[1] = 1){
                    board[i][j] += s[5];
                }
            }
        }
        
        for(auto s : board){
            for(auto d : s){
                cout << d << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    
    for(auto s : board){
        for(auto d : s){
            if(d > 0)
                answer++;
        }
    }
    
    
    return answer;
}*/