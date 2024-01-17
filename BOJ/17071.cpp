#include <bits/stdc++.h>
using namespace std;

int visited[2][500005];
int N,K,min_second = INT_MAX;

void bfs()
{
    queue<pair<int,int>> q;

    visited[0][N] = 1;
    q.push({N,0});

    while(!q.empty()){
        int loc, time;
        tie(loc, time) = q.front(); q.pop();

        for(int next : {loc-1, loc+1, loc*2}){
            if(next < 0 || next > 500000 || visited[(time+1)%2][next])
                continue;

            visited[(time+1)%2][next] = visited[time%2][loc] + 1;
            q.push({next,time+1});
        }
        
    }
}
int main()
{
    scanf("%d %d",&N, &K);
    memset(visited,0,sizeof(visited));
    bfs();

    int next; bool flag = false;
    for(int i = 0 ; i < 500000 ; i++){
        next = K + (i*(i+1))/2;
        if(next > 500000) break;
        if(visited[i%2][next] && visited[i%2][next]-1 <= i){
            printf("%d\n",i);
            flag = true;
            break;
        }
    }
    if(!flag)
        printf("-1\n");
}
