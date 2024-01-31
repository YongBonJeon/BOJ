### 문제
2023 KAKAO BLIND RECRUITMENT - Lv.3
<https://school.programmers.co.kr/learn/courses/30/lessons/150366>

### 풀이
초기에 2차원 vector로 문제를 해결하려고 했으나 로직이 너무 복잡했고 시간초과로 인해 실패했다. graph\[i]\[j]의 vector에 {i,j}와 Merge되어 있는 pair들을 모두 넣는 방식이었는데 굉장히 비효율적임을 알고 Union-find 방식에서 아이디어를 얻어 다음 방식으로 문제를 해결했다.

우선 로직을 간단하게 하기 위해 병합 정보와 컨텐츠 정보를 분리하기 위해 2개의 2차원 배열을 사용했다. 병합 정보를 나타내는 graph\[51]\[51]은 로직을 최대한 간단하게 하기 위해 부모와 자식간의 rank는 모두 1이다.

Command 별 로직
1. Update r c value
- graph\[r]\[c]가 가르키는 곳의 content를 value로 변경한다. (graph\[r]\[c]는 병합 여부에 따라 {r,c}일 수도 아닐 수도 있다.)

2. Update value1 value2
- graph 혹은 content 배열을 순회하며 value1을 value2로 변경한다.

3. Merge r1 c1 r2 c2
- 셀을 병합할 때 value는 {r1,c1}이 가르키는 value가 우선이다.
- graph\[r2]\[c2]와 같은 곳을 가르키고 있는 pair들을 찾는다. (같은 부모를 가진 pair들이며 {r2,c2}와 같이 병합되어 있음을 나타낸다.)
- 위에서 찾은 pair들의 graph\[pair]의 값을 graph\[r1]\[c1]으로 변경한다. ({r1,c1}의 부모(혹은 자신)와 같은 값을 나타내게 함으로써 병합을 의미한다.
- 처음에 찾은 우선 value로 변경한다.

4. Unmerge r c
- grpah\[r]\[c]와 같은 곳을 가르키고 있는 pair들을 찾는다.
- 위에서 찾은 pair들의 graph\[pair]들의 값을 {pair}로 변경하고 컨텐츠 정보를 비운다. (모두 자기 자신을 가르키게 함으로써 병합 해제를 의미한다.)

5. Print r c
- graph\[r]\[c]가 가르키는 곳의 컨텐츠 정보를 출력한다.

### Code
```cpp
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

pair<int,int> graph[51][51];
string contents[51][51];

vector<string> split(string total_cmd){
    vector<string> cmd;
    long long pos;
    while((pos = total_cmd.find(" ")) != string::npos){
        cmd.push_back(total_cmd.substr(0,pos));
        total_cmd.erase(0,pos+1);
    }
    cmd.push_back(total_cmd);
    
    return cmd;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for(int i = 1 ; i <= 50 ; i++){
        for(int j = 1 ; j <= 50 ; j++){
            graph[i][j] = {i,j};
            contents[i][j] = "EMPTY";
        }
    }
    
    for(string total_cmd : commands){
        vector<string> cmd = split(total_cmd);
        if(!cmd[0].compare("UPDATE")){
            // "UPDATE r c value"
            if(cmd.size() == 4){
                int r = stoi(cmd[1]);
                int c = stoi(cmd[2]);
                string value = cmd[3];
                
                contents[graph[r][c].first][graph[r][c].second] = value;
            }
            
            // "UPDATE value1 value2"
            else if(cmd.size() == 3){
                string value1 = cmd[1];
                string value2 = cmd[2];
                for(int i = 1 ; i <= 50 ; i++){
                    for(int j = 1 ; j <= 50 ; j++){
                            if(!contents[i][j].compare(value1))
                                contents[i][j] = value2;
                    }
                }
            }
        }
        
        //"MERGE r1 c1 r2 c2"
        else if(!cmd[0].compare("MERGE")){
            int r1 = stoi(cmd[1]);
            int c1 = stoi(cmd[2]);
            int r2 = stoi(cmd[3]);
            int c2 = stoi(cmd[4]);
            string value = contents[graph[r1][c1].first][graph[r1][c1].second];
            if(!value.compare("EMPTY"))
                value = contents[graph[r2][c2].first][graph[r2][c2].second];
            
            if(graph[r1][c1].first == graph[r2][c2].first 
              && graph[r1][c1].second == graph[r2][c2].second)
                continue;

            vector<pair<int,int>> temp;
            for(int i = 1 ; i <= 50 ; i++){
                for(int j = 1 ; j <= 50 ; j++){
                    if(graph[i][j].first == graph[r2][c2].first
                          && graph[i][j].second == graph[r2][c2].second){
                        temp.push_back({i,j});
                    }
                }
            }
            for(auto t : temp){
                graph[t.first][t.second] = {graph[r1][c1].first, graph[r1][c1].second};
            }
            contents[graph[r1][c1].first][graph[r1][c1].second] = value;
            temp.clear();
        }

        // "UNMERGE r c"
        else if(!cmd[0].compare("UNMERGE")){
            int r = stoi(cmd[1]);
            int c = stoi(cmd[2]);
            string value = contents[graph[r][c].first][graph[r][c].second];
            
            vector<pair<int,int>> temp;
            for(int i = 1 ; i <= 50 ; i++){
                for(int j = 1 ; j <= 50 ; j++){
                    if(graph[i][j].first == graph[r][c].first 
                       && graph[i][j].second == graph[r][c].second){
                        temp.push_back({i,j});
                        
                    }
                }
            }
            for(auto t : temp){
                graph[t.first][t.second] = {t.first,t.second};
                contents[t.first][t.second] = "EMPTY";
            }
            contents[r][c] = value;
        }
        // "PRINT r c"
        else if(!cmd[0].compare("PRINT")){
            int r = stoi(cmd[1]);
            int c = stoi(cmd[2]);
             
            answer.push_back(contents[graph[r][c].first][graph[r][c].second]);
        }
    }
    
    return answer;
}
```
