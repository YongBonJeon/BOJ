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