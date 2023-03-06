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