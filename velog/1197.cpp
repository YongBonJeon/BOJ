#include <bits/stdc++.h>
using namespace std;

// Find-union 으로 간선 가중치 정렬해서 하는 법 
// 한 정점에서 시작해서 최소 가중치 간선 더하며 스패닝 트리 구성

int V,E;
vector<tuple<int,int,int>> edge;

int parent[100001];

int find(int v){
    if(parent[v] == v)
        return v;
    else
        return find(parent[v]);
}

// x가 부모
void union_(int x, int y){
    x = find(x);
    y = find(y);

    parent[y] = x;
}

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}

int main()
{
    scanf("%d %d",&V,&E);
    int st,dt,w;
    for(int i = 0 ; i < E ; i++){
        scanf("%d %d %d",&st, &dt, &w);

        edge.push_back({st,dt,w});
    }

    for(int i = 1 ; i <= V ; i++)
        parent[i] = i;

    sort(edge.begin(),edge.end(),cmp);

    int sum = 0;
    for(int i = 0 ; i < E ; i++){
        if(find(get<0>(edge[i])) != find(get<1>(edge[i]))){
            //printf("%d %d\n",get<0>(edge[i]),get<1>(edge[i]));
            sum += get<2>(edge[i]);
            union_(get<0>(edge[i]),get<1>(edge[i]));
        }
    }
    printf("%d\n",sum);
}