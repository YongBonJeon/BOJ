#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int parent[20];
vector<int> adj[20];
int max_ans = 0;

int find(int v){
    if(parent[v] == v)
        return v;
    else
        return parent[v] = find(parent[v]);
}

void union_(int u, int v){
    u = find(u);
    v = find(v);
    
    parent[v] = u;
}

void dfs(int wolf, int sheep, vector<int> info, int depth){
    if(wolf >= sheep){
        return ;
    }
    max_ans = max(max_ans, sheep);
    
    // 방문하지 않은 노드가 모두 양이어도 max값을 넘을 수는 없으므로 종료
    if(max_ans >= sheep + info.size()-(depth+1))
        return ;
    
    
    // 아직 방문하지 않은 노드 중
    for(int i = 1 ; i < info.size() ; i++){
        bool flag = false;
        // 이미 방문한 노드에 갈 수 있다면
        for(auto already : adj[i]){
            if(i == find(i) && find(0) == find(already)){
                flag = true;
                break;
            }
        }
        if(flag){
            int temp[20];
            for(int i = 0 ; i < info.size() ; i++) temp[i] = parent[i];
            union_(0,i);
            if(info[i] == 0){
                dfs(wolf,sheep+1,info,depth+1);
            }
            else if(info[i] == 1){
                dfs(wolf+1,sheep,info,depth+1);
            }
            for(int i = 0 ; i < info.size() ; i++) parent[i] = temp[i];
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    for(int i = 0 ; i <= info.size() ; i++){
        parent[i] = i;
    }
    dfs(0,1,info,0);
    cout << max_ans << '\n';
    return max_ans;
}