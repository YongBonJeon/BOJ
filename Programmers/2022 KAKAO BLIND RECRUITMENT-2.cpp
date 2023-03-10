#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int is_prime(string x){
    if(x == "")
        return 0;
    long long intx = atoll(x.c_str());
    if(intx == 1)
        return 0;
    
    for(long long i = 2; i <= sqrt(intx); i++) {
       if(intx % i == 0) {
          return 0;
       }
    }
    return 1;
}

int solution(int n, int k) {
    int answer = 0;
    string ch = "";
    // K진수로 변환 5 
    while(n > 0){
        ch += to_string(n%k);
        n /= k;
    }
    reverse(ch.begin(), ch.end());
    int pos;
    while((pos = ch.find("0")) != string::npos){
        answer += is_prime(ch.substr(0,pos));
        ch.erase(0,pos+1);
    }
    answer += is_prime(ch);
    cout << answer << '\n';
    
    
    
    return answer;
}