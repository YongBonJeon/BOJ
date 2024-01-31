### 문제
<https://school.programmers.co.kr/learn/courses/30/lessons/150370>

### 풀이
Parsing만 제대로 한다면 어렵지 않게 풀 수 있었던 문제였다.
끝나고 비슷한 문제들을 풀며 느낀 것은 년, 월에 가중치를 곱해서 년,월,일을 다 더해서 모두 합쳐진 value를 통해서 해결한다면 이런 year/month/day 유형의 문제를 더 쉽게 풀 수 있음을 인지했다.

### Code
```cpp
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
```
