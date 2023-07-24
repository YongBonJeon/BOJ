#include <bits/stdc++.h>
using namespace std;

int N,max_dist,num_edge;
int items[101];
const int intMax = 987654321;
vector<pair<int, int>> graph[101];

int main(){

    scanf("%d %d %d",&N, &max_dist, &num_edge);

    for(int i = 1 ; i <= N ; i++){
        scanf("%d",&items[i]);
    }

    int v1,v2,w;
    for(int i = 0 ; i < num_edge ; i++){
        scanf("%d %d %d",&v1, &v2, &w);
        graph[v1].push_back({v2,w});
        graph[v2].push_back({v1,w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>> pq;

    int max_ans = 0, temp_ans;
    int dist[101];

    for(int i = 1 ; i <= N ; i++){
        temp_ans = 0;
        for(int i = 1 ; i<= N ; i++) dist[i] = intMax;
        
        dist[i] = 0;
        pq.push({0,i});

        int cur,next,nw;
        while(!pq.empty()){
            cur = pq.top().second;
            w = -pq.top().first;
            pq.pop();

            for(auto x : graph[cur]){
                next = x.first;
                nw = w + x.second;

                if(nw < dist[next]){
                    dist[next] = nw;
                    pq.push({-nw, next});
                }
            }
        }

        for(int i = 1 ; i <= N ; i++){
            if(dist[i] <= max_dist) temp_ans += items[i];
        }
        max_ans = max(max_ans, temp_ans);
    }
    printf("%d\n",max_ans);
}