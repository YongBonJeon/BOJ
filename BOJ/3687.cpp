#include <bits/stdc++.h>
using namespace std;

int T;
int sn[10] = {6,2,5,5,4,5,6,3,7,6};
string dp[101];
string max_str = "11111111111111111111111111111111111111111111111111";

string min_str(string a, string b){
    if(a.size() == b.size()) return (a < b ? a : b); 
	if(a.size() < b.size()) return a; 
	return b;  
}


// 가장 큰 수 : 가능한 적게 사용하는 성냥 중에서 가장 큰 값을 사용
string find_max_str(int n){
    string temp;
    if(n%2){
        temp += '7';
        n -= 3;
    }
    while(n != 0){
        temp += '1';
        n -= 2;
    }
    return temp;
}

int main(){
    cin >> T;
    int n;

    fill(dp,dp+101,max_str);
    dp[0] = "";

    // 가장 작은수 : 가능한 많이 사용하는 성냥 중에서 가장 작은 값을 사용 
    for(int i = 2 ; i <= 100 ; i++){
        for(int j = 0 ; j <= 9 ; j++){
            if(i-sn[j] < 0) continue;
            if(j == 0 && dp[i-sn[j]] == "") continue;
            dp[i] = min_str(dp[i], dp[i-sn[j]]+to_string(j));
        }
    }

    for(int i = 0 ; i < T ; i++){
        cin >> n;
        cout << dp[n] << ' ' << find_max_str(n) <<'\n';
    
    }

    

    
}