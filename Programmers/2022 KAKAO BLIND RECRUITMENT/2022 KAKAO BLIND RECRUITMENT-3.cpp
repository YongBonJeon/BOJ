#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int transform(string s){
    int hour = stoi(s.substr(0,2));
    int minute = stoi(s.substr(3,5));
    
    return hour*60+minute;
}

int cal(int x, vector<int> fees){
    int total = 0;
    total += fees[1];
    if(x < fees[0])
        return total;
    if((x-fees[0])%fees[2])
        total += (x-fees[0]+fees[2])/fees[2]*fees[3];
    else
        total += (x-fees[0])/fees[2]*fees[3];
    
    return total;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<int> go(10000, 0);
    vector<int> car;
    
    for(string s : records){
        car.push_back(stoi(s.substr(6,10)));
        if(s.substr(11) == "IN"){
            go[stoi(s.substr(6,10))] -= transform(s);
        }
        else{
            go[stoi(s.substr(6,10))] += transform(s);
        }
        //cout << stoi(s.substr(6,10)) << " "<< go[stoi(s.substr(6,10))] << '\n';
    }
    sort(car.begin(),car.end());
    car.erase(unique(car.begin(),car.end()),car.end());
    
    for(int v : car){
        if(go[v] <= 0){
            go[v] += transform("23:59");
        }
        //cout << v << " "<<  go[v] << '\n';
        go[v] = cal(go[v],fees);
        //cout << v << " "<<  go[v] << '\n';
        answer.push_back(go[v]);
    }
    
    return answer;
}