#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int INF = 98765321;
int max_ans = 0;
vector<int> max_vector(11,0);
vector<int> lion(11,0);

vector<int> select(vector<int> a, vector<int> b){
    for(int i = 10 ; i >= 0 ; i--){
        if(a[i] == b[i])
            continue;
        else if(a[i] > b[i])
            return a;
        else
            return b;
    }
}

void dfs(int start, int n, int sum, vector<int> info){
    if(start == 10){
        lion[start] += n;
        
        if(max_ans < sum){
            max_ans = max(max_ans, sum);
            max_vector = lion;
        }
        else if(max_ans == sum){
            max_vector = select(max_vector,lion);
        }
        lion[start] -= n;
        
        return ;   
    }
    
    // 현재 과녁으로 점수 얻을래 말래
    // 남은 화살이 어피치보다 많아야 함
    if(n > info[start]){
        // 라이언 점수 획득
        lion[start] += (info[start]+1);
        dfs(start+1, n-(info[start]+1), sum+(10-start),info);
        lion[start] -= (info[start]+1);
    }
    // 점수 미획득
    // 둘 다 점수 미획득
    if(info[start] == 0)
        dfs(start+1, n, sum, info);
    // 어피치 점수 획득
    if(info[start] > 0)
        dfs(start+1, n, sum-(10-start),info);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    answer.push_back(-1);
    
    dfs(0,n,0,info);
    
    //cout << max_ans << '\n';
    
    if(max_ans == 0)
        return answer;
    return max_vector;
}