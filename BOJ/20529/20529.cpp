#include <bits/stdc++.h>
using namespace std;

map<string, int> MBTI;
map<int, string> r_MBTI;
int num_MBTI[16];

int dist_MBTI(string a, string b){
    int val = 0;
    for(int i = 0 ; i < 4 ; i++){
        if(a[i] != b[i]) val++;
    }
    return val;
}

int three_MBTI(int i, int j, int k){
    int val = 0;

    val += dist_MBTI(r_MBTI[i], r_MBTI[j]);
    val += dist_MBTI(r_MBTI[j], r_MBTI[k]);
    val += dist_MBTI(r_MBTI[k], r_MBTI[i]);

    return val;
}

int main(){
    MBTI["ISTJ"] = 0; MBTI["ISFJ"] = 1; MBTI["INFJ"] = 2; MBTI["INTJ"] = 3;
    MBTI["ISTP"] = 4; MBTI["ISFP"] = 5; MBTI["INFP"] = 6; MBTI["INTP"] = 7;
    MBTI["ESTP"] = 8; MBTI["ESFP"] = 9; MBTI["ENFP"] = 10; MBTI["ENTP"] = 11;
    MBTI["ESTJ"] = 12; MBTI["ESFJ"] = 13; MBTI["ENFJ"] = 14; MBTI["ENTJ"] = 15;
    r_MBTI[0] = "ISTJ"; r_MBTI[1] = "ISFJ"; r_MBTI[2] = "INFJ"; r_MBTI[3] = "INTJ";
    r_MBTI[4] = "ISTP"; r_MBTI[5] = "ISFP"; r_MBTI[6] = "INFP"; r_MBTI[7] = "INTP";
    r_MBTI[8] = "ESTP"; r_MBTI[9] = "ESFP"; r_MBTI[10] = "ENFP"; r_MBTI[11] = "ENTP";
    r_MBTI[12] = "ESTJ"; r_MBTI[13] = "ESFJ"; r_MBTI[14] = "ENFJ"; r_MBTI[15] = "ENTJ";

    int T;

    cin >> T;

    int N;
    string p_MBTI;
    while(T--){
        for(int i = 0 ; i < 16 ; i++) num_MBTI[i] = 0;
        cin >> N;
        for(int i = 0 ; i < N ; i++){
            cin >> p_MBTI;
            
            num_MBTI[MBTI[p_MBTI]]++;
        }
        
        int ans = 1000000;
        for(int i = 0 ; i < 16 ; i++){
            num_MBTI[i]--;
            for(int j = 0 ; j < 16 ; j++){
                num_MBTI[j]--;
                for(int k = 0 ; k < 16 ; k++){
                    num_MBTI[k]--;
                    if(num_MBTI[i] >= 0 && num_MBTI[j] >= 0 && num_MBTI[k] >= 0){
                        ans = min(ans, three_MBTI(i,j,k));
                    }
                    num_MBTI[k]++;
                }
                num_MBTI[j]++;
            }
            num_MBTI[i]++;
        }
        cout << ans << '\n';
    }
}