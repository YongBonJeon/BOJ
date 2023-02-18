#include <bits/stdc++.h>
using namespace std;

typedef struct _edge{
    int st;
    int dt;
    int weight;
}edge;

int V,E;

vector<edge> edges;
int parent[100001];

int find(int v){
    if(parent[v] == v)
        return v;
    else
        return parent[v] = find(parent[v]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    parent[v] = u;
}

int cmp(edge a, edge b){
    return a.weight < b.weight;
}

int main(){
    int st,dt,w;

    scanf("%d %d",&V, &E);
    for(int i = 0 ; i < E ; i++){
        scanf("%d %d %d",&st,&dt,&w);
        edges.push_back({st,dt,w});    
    }

    for(int i = 1 ; i <= V ; i++)
        parent[i] = i;
    
    sort(edges.begin(), edges.end(), cmp);

    int sum = 0;
    int max_ = 0;
    for(int i = 0 ; i < E ; i++){
        if(find(edges[i].st) != find(edges[i].dt)){
            merge(edges[i].st,edges[i].dt);

            sum += edges[i].weight;
            max_ = max(max_,edges[i].weight);
        }
    }
    printf("%d\n",sum-max_);
}