#include <bits/stdc++.h>
using namespace std;

int T,N,K,X,Y,W;
int cost[1004];
int DP[1004];
vector<int> adj[1004];
int indegree[1004];


int main(){
    scanf("%d",&T);
    for(int i = 0 ; i < T ; i++){
        for(int j = 1 ; j <= N ; j++){
            cost[j] = 0;
            DP[j] = 0;
            indegree[j] = 0;
        }
        queue<int> q;

        scanf("%d %d",&N, &K);
        for(int j = 1 ; j <= N ; j++){
            scanf("%d",&cost[j]); DP[j] = cost[j];
            adj[j].clear();
        }

        // incoming edge 계산
        for(int j = 0 ; j < K ; j++){
            scanf("%d %d",&X,&Y);
            adj[X].push_back(Y);
            indegree[Y]++;
        }
        scanf("%d",&W);
        // incoming edge가 0개인 vertex queue push
        for(int j = 1 ; j <= N ; j++){
            if(j == W)  continue;
            if(indegree[j] == 0)
                q.push(j);
        }

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for(auto x : adj[temp]){
                DP[x] = max(DP[x],DP[temp] + cost[x]);
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }

        printf("%d\n",DP[W]);
    }

}

// DP[1] = 10
// DP[2] = 11
// DP[3] = 110
// DP[4] = 21 + DP[4] = 120