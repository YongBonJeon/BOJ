#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//Map<pair<ll,ll>,int> dp;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    ll sum = 0;
    ll target, cur;
    vector<int> q12;
    int size1 = queue1.size();
    // 초기 두 큐의 합
    for(int i = 0 ; i < size1 ; i++){
        sum += queue1[i];
        q12.push_back(queue1[i]);
    }
    cur = sum;
    int size2 = queue2.size();
    for(int j = 0; j < size2 ; j++){
        sum += queue2[j];
        q12.push_back(queue2[j]);
    }
    target = sum/2;
    
    int size = q12.size();
    int l = 0, r = queue1.size()-1;
    
    int i = 0;
    while(l < size && r < size){
        if(cur > target){
            // 합이 작아진다
            cur -= q12[l];
            l++;
            
        }
        else if(cur < target){
            // 합이 커진다 
            r++;
            cur += q12[r];
        }
        else{
            //cout << l << " " << r << '\n';
            return i;
            break;
        }
        i++;
    }
    // 0~3 | 4~7
    // 3 2 7 2 | 4 6 5 1
    // 3 | 2 7 2 4 | 6 5 1
    // 1 2 1 2 1 | 10 |  1 2
    
    return -1;
}