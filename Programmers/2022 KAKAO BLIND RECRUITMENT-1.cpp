#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

map<string, int> rpt;
map<string, int> rev;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for(auto id : id_list)
        rpt[id] = 0;
    
    sort(report.begin(),report.end());
    report.erase(unique(report.begin(),report.end()),report.end());
    
    for(auto r : report){
        //cout << r << '\n';
        int pos = r.find(" ");
        
        rpt[r.substr(pos+1)]++;
    }
    
    for(auto r : rpt){
        if(r.second >= k){
            for(auto p : report){
                int pos = p.find(" ");
                if(!p.substr(pos+1).compare(r.first)){
                    rev[p.substr(0,pos)]++;
                }
            }
        }
    }
    
    for(int i = 0 ; i < id_list.size() ; i++){
        bool flag = false;
        for(auto sib : rev){
            //cout << sib.first << " " << sib.second << '\n';
            if(!sib.first.compare(id_list[i])){
                answer.push_back(sib.second);
                flag = true;
                break;
            }
        }
        if(!flag)
            answer.push_back(0);
    }
    
    for(auto x : answer)
        cout << x << " ";
    

    
    return answer;
}