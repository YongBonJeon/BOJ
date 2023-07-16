#include <bits/stdc++.h>
using namespace std;
bool visited[100001];
bool mark[100001];
int team[100001];
int ans;

void dfs(int cur){
    visited[cur] = true;

    if(!visited[team[cur]])
        dfs(team[cur]);
    else if(!mark[team[cur]]){
        ans--;
        for(int dest = team[cur] ; dest != cur; dest = team[dest])
            ans--;
    }

    mark[cur] = true;
}

int main(){
    int T;

    scanf("%d",&T);

    while(T--){
        int N;
        scanf("%d",&N);
        ans = N;

        for(int i = 1 ; i <= N ; i++){
            scanf("%d",&team[i]);
            visited[i] = false;
            mark[i] = false;
        }

        for(int i = 1 ; i <= N ; i++){
            if(!visited[i])
                dfs(i);
        }
        printf("%d\n",ans);
    }



}