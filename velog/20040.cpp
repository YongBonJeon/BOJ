#include <bits/stdc++.h>
using namespace std;

int parent[500001];

int find(int v){
    if(parent[v] == v)
        return v;
    else
        return parent[v] = find(parent[v]);
}

void union_(int x, int y){
    x = find(x);
    y = find(y);

    parent[y] = x;
}

int main(){
    int n,m;

    scanf("%d %d",&n, &m);
    for(int i = 0 ; i < n ; i++){
        parent[i] = i;
    }
    int st,dt;
    int ret = 0;
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d",&st,&dt);

        if(ret)
            continue;
        if(find(st) != find(dt)){
            union_(st,dt);
        }
        else{
            ret = i+1;
        }
    }
    printf("%d\n",ret);
}