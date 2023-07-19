#include <bits/stdc++.h>
using namespace std;

// 1 to N : 중복 방문, 이동 가능 : 최단거리
// 1 to v1 to v2 to N
// 1 to v2 to v1 to N

const int intmax = 987653210;
int N,E, v1, v2;
vector<pair<int, int>> graph[801];
int dist1[801];
int dist2[801];
int dist3[801];
int dist4[801];

int main(){
    scanf("%d %d",&N, &E);

    int st,dt,w;
    for(int i = 0 ; i < E ; i++){
        scanf("%d %d %d",&st, &dt, &w);
        graph[st].push_back({dt,w});
        graph[dt].push_back({st,w});
    }

    scanf("%d %d",&v1,&v2);

    for(int i = 0 ; i <= 800 ; i++){
        dist1[i] = intmax;
        dist2[i] = intmax;
        dist3[i] = intmax;
        dist4[i] = intmax;
    }
        
    // {-거리, 정점}
    priority_queue<pair<int,int>, vector<pair<int,int>>> pq;

    int cur,weight,next,next_weight;

    // 1 to v1, v2
    pq.push({0,1});
    dist1[1] = 0;
    while(!pq.empty()){
        weight = pq.top().first*(-1);
        cur = pq.top().second;
        pq.pop();

        for(auto x : graph[cur]){
            next = x.first;
            next_weight = weight + x.second;
            if(next_weight < dist1[next]){
                dist1[next] = next_weight;
                pq.push({-next_weight, next});
            }
        }
    }

    // v1 to v2, N
    pq.push({0,v1});
    dist2[v1] = 0;
    while(!pq.empty()){
        weight = pq.top().first*(-1);
        cur = pq.top().second;
        pq.pop();

        for(auto x : graph[cur]){
            next = x.first;
            next_weight = weight + x.second;
            if(next_weight < dist2[next]){
                dist2[next] = next_weight;
                pq.push({-next_weight, next});
            }
        }
    }

    // v2 to v1, N
    pq.push({0,v2});
    dist3[v2] = 0;
    while(!pq.empty()){
        weight = pq.top().first*(-1);
        cur = pq.top().second;
        pq.pop();

        for(auto x : graph[cur]){
            next = x.first;
            next_weight = weight + x.second;
            if(next_weight < dist3[next]){
                dist3[next] = next_weight;
                pq.push({-next_weight, next});
            }
        }
    }

    int ans = -1;
    if(dist1[v1] != intmax && dist2[v2] != intmax && dist3[N] != intmax)
        ans = min(dist1[v1]+dist2[v2]+dist3[N],
                        dist1[v2]+dist3[v1]+dist2[N]);
    if(dist1[v2] != intmax && dist3[v1] != intmax && dist2[N] != intmax)
        ans = min(dist1[v1]+dist2[v2]+dist3[N],
                        dist1[v2]+dist3[v1]+dist2[N]);

    printf("%d\n",ans);
}