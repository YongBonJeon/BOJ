#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int arr[26];
    for(string s : terms){
        arr[s[0]-'A'] = stoi(s.substr(2));
    }
    int todayYear = stoi(today.substr(0,4));
    int todayMonth = stoi(today.substr(5,7));
    int todayDay = stoi(today.substr(8,10));
    
    //cout << validYear << " " << validMonth << " " << validDay << '\n';
    
    for(int i = 1 ; i <= privacies.size() ; i++){
        string s = privacies[i-1];
        int pos = s.find('.');
        int year = stoi(s.substr(0,pos));
        s.erase(0,pos+1);
        pos = s.find('.');
        int month = stoi(s.substr(0,pos));
        s.erase(0,pos+1);
        pos = s.find(' ');
        int day = stoi(s.substr(0,pos));
        s.erase(0,pos+1);
        
        
        month += arr[s[0]-'A'];
        day -= 1;
        
        if(day == 0){
            month -= 1;
            day = 28;
        }
        while(month > 12){
            year += 1;
            month -= 12;
        }
        
        if(todayYear > year){
            answer.push_back(i);
        }
        else if(todayYear < year){
            continue;
        }
        else if(todayYear == year){
            if(todayMonth > month){
                answer.push_back(i);
            }
            else if(todayMonth < month){
                continue;
            }
            else if(todayMonth == month){
                if(todayDay > day){
                    answer.push_back(i);
                }
                else if(todayDay <= day){
                    continue;
                }
            }
        }    
    }
    return answer;
}