#include <bits/stdc++.h>
using namespace std;

int N,K;
int visited[100001];
int direction[1000001];
int min_value = INT_MAX;
int min_count = 0;
/* 5 10 9 18 17*/
/* 5 4 8 16 17*/
void bfs()
{
    queue<int> q;
    int cur,next;

    visited[N] = 1;
    q.push(N);

    while(!q.empty())
    {
        cur = q.front(); q.pop();

        if(cur == K){
            if(visited[cur] < min_value){
                min_value = visited[cur];
            }
            return ;
        }

        for(int i = 0 ; i < 3 ; i++)
        {
            if(i == 0)
                next = cur + 1;
            else if(i == 1)
                next = cur - 1;
            else
                next = cur * 2;
            
            if(next < 0 || next > 100000)
                continue;
        
            if(!visited[next] || visited[next] > visited[cur] + 1)
            {
                q.push(next);
                visited[next] = visited[cur] + 1;
                direction[next] = i+1;
            }
        }
         
    }
    return ;
}

vector<int> path;
void print_path()
{
    int v = K;

    while(v != N)
    {
        path.push_back(v);
        if(direction[v] == 1)
            v = v - 1;
        else if(direction[v] == 2)
            v = v + 1;
        else if(direction[v] == 3)
            v = v / 2;
    }
    path.push_back(N);
}

int main()
{
    scanf("%d %d",&N,&K);

    memset(visited,0,sizeof(visited));
    bfs();
    
    printf("%d\n",min_value-1);
    print_path();
    for(int i = path.size()-1 ; i >= 0 ; i--)
        printf("%d ",path[i]);
    printf("\n");
}