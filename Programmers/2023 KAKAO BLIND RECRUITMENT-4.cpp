#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
// 재귀로 풀어야 한다 

/*bool solve(ll x, ll cur, ll depth, int prev){
    int ret = 1, d = pow(2,depth-2);
    
    // 부모 중에 0이 존재한다면 자식은 1이면 안된다. 
    if(prev == 0){
        if((x & (1 << (cur-1))) > 0){
            return false;
        }
    }
    
    if(depth == 1){
        return true;
    }

    return solve(x,cur-d,depth-1, prev & ((x & (1 << (cur-1))) > 0)) 
        && solve(x,cur+d,depth-1, prev & ((x & (1 << (cur-1))) > 0));
    
    
}

vector<int> solution(vector<ll> numbers) {
    vector<int> answer;
    
    for(auto n : numbers){
        ll height = 1;
        while(n > pow(2,pow(2,height)-1)-1){
            height++;
        }
        
        ll mid = pow(2,height-1);
        
        int ans = solve(n, mid, height,1);
        answer.push_back(ans);
        //printf("\n\n");
    }
    
    return answer;
}*/

bool solve(string ret, int len){
    bool flag = true;
    for(auto c : ret){
        if(c == '1')
            flag = false;
    }
    if(len == 1 || flag){
        return true;
    }
    int mid = len/2;
    string right = ret.substr(mid+1);
    string left = ret.substr(0,mid);
    
    
    return ret[mid] == '1'
        && solve(right,right.length()) 
        && solve(left,left.length());
    
    
}

vector<int> solution(vector<ll> numbers) {
    vector<int> answer;
    
    for(auto n : numbers){
        string ret = "";
        
        while(n > 0){
            ret += to_string(n%2);
            n >>= 1;
        }
        int len = 2;
        while(len-1 < ret.length()){
            len *= 2;
        }
        for(int i = ret.length() ; i < len-1 ; i++){
            ret += "0";
        }
        reverse(ret.begin(),ret.end());
        
        answer.push_back(solve(ret,ret.length()));
    }
    
    return answer;
}


