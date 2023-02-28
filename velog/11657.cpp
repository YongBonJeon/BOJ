#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INF = 9876543210;
int N,M,st,dt,w;
vector<pair<int,int>> adj[505];
ll dist[505];

int main(){
    scanf("%d %d",&N, &M);
    for(int i = 0 ; i < M ; i++){
        scanf("%d %d %d",&st,&dt,&w);
        adj[st-1].push_back({dt-1,w});
    }

    fill(dist, dist+N,INF);

    dist[0] = 0; bool cycle = false;

    // N번 반복
    for(int i = 0 ; i < N ; i++){
        for(int here = 0 ; here < N ; here++){
            for(auto edge : adj[here]){
                int dt = edge.first;
                int w = edge.second;

                if(dist[here] == INF) continue;
                if(dist[dt] > dist[here] + w){
                    if(i == N-1) cycle = true;
                    dist[dt] = dist[here] + w;
                }
            }
        }
    }

    if(cycle)
        printf("-1\n");
    else{
        for(int i = 1 ; i < N ; i++){
            printf("%lld\n",(dist[i] != INF ? dist[i] : -1));
        }
    }
}