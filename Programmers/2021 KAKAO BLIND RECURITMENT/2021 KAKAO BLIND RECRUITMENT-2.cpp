#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    ll p_sum[360001] = {0,};
    
    for(string log : logs) {
        int start = stoi(log.substr(0,2))*3600
            + stoi(log.substr(3,5))*60 + stoi(log.substr(6,8));
        int end = stoi(log.substr(9,11))*3600
            + stoi(log.substr(12,14))*60 + stoi(log.substr(15,17));
        
        p_sum[start] += 1;
        p_sum[end] -= 1;
    }
    
    ll sum = 0;
    for(int i = 0 ; i < 360000 ; i++) {
        sum += p_sum[i];
        p_sum[i] = sum;
    }
    
    int play_time_int = stoi(play_time.substr(0,2))*3600 + stoi(play_time.substr(3,5))*60 + stoi(play_time.substr(6,8));
    int adv_time_int = stoi(adv_time.substr(0,2))*3600 + stoi(adv_time.substr(3,5))*60 + stoi(adv_time.substr(6,8));
    
    ll max_ans = 0;
    int max_idx = 0;
    
    ll temp_ans = 0;
    for(int i = 0 ; i < adv_time_int ; i++) {
        temp_ans += p_sum[i];
    }
    max_ans = temp_ans;
    max_idx = 0;
    
    for(int i = 0 ; i < play_time_int - adv_time_int ; i++) {
        temp_ans += p_sum[adv_time_int + i];
        temp_ans -= p_sum[i];
        
        if(temp_ans > max_ans) {
            max_ans = temp_ans;
            max_idx = i+1;
        }
    }
    

    if(max_idx/3600 < 10)
        answer += "0";
    answer += to_string(max_idx/3600);
    answer += ":";
    max_idx %= 3600;
    if(max_idx/60 < 10)
        answer += "0";
    answer += to_string(max_idx/60);
    answer += ":";
    max_idx %= 60;
    if(max_idx < 10)
        answer += "0";
    answer += to_string(max_idx);
    
    return answer;
}