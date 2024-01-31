### 문제
<https://school.programmers.co.kr/learn/courses/30/lessons/150368>

### 풀이
백트래킹 완전 탐색으로 어렵지 않게 문제를 해결할 수 있었다. 각 이모티콘 별로 10%,20%,30%,40% 할인율에 대한 모든 탐색을 진행하고 각 할인율에 대해 모든 유저를 탐색하며 해당 이모티콘을 살 것인지 확인한다.

최종적으로 모든 이모티콘을 순회한 뒤 유저가 구매한 금액을 확인하며 이모티콘 플러스 가입 여부와 이모티콘 구매액을 확인하면서 최댓값을 찾는다.

### Code
```cpp
#include <string>
#include <vector>

using namespace std;

int ubuy[101];
int max_login = 0;
int max_buy = 0;

void back(int idx,vector<vector<int>> users, vector<int> emoticons){
    if(idx == emoticons.size()){
        int temp_login = 0, temp_buy = 0;
        for(int i = 0 ; i < users.size() ; i++){
            if(ubuy[i] >= users[i][1]){
                temp_login++;
            }
            else{
                temp_buy += ubuy[i];
            }
        }
        if(max_login < temp_login){
            max_login = temp_login;
            max_buy = temp_buy;
        }
        else if(max_login == temp_login)
            max_buy = max(max_buy, temp_buy);
        return ;
    }
    
    
    for(int sale = 10 ; sale <= 40 ; sale += 10){
        for(int u = 0 ; u < users.size() ; u++){
            if(sale >= users[u][0]){
                ubuy[u] += (emoticons[idx]*(100-sale))/100;
            }
        }
        back(idx+1,users,emoticons);
        
        for(int u = 0 ; u < users.size() ; u++){
            if(sale >= users[u][0]){
                ubuy[u] -= (emoticons[idx]*(100-sale))/100;

            }
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    back(0,users,emoticons);
    
    answer.push_back(max_login);
    answer.push_back(max_buy);
    
    return answer;
}
```
