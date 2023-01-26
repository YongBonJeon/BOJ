#include <bits/stdc++.h>
using namespace std;

int N,K;
int visited[100001];
int min_value = INT_MAX;
int min_count = 0;

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
                min_count=1;
            }
            else if(visited[cur] == min_value){
                min_count++;
            }
        }

        for(int i = 0 ; i < 3 ; i++)
        {
            if(i == 0)
                next = cur + 1;
            else if(i == 1)
                next = cur - 1;
            else
                next = cur*2;

            if(next < 0 || next > 100000)
                continue;
            
            if(!visited[next] || visited[next] >= visited[cur]+1)
            {
                q.push(next);
                visited[next] = visited[cur] + 1;
            }
        }
    }
    return ;
}

int main()
{
    scanf("%d %d",&N,&K);

    memset(visited,0,sizeof(visited));
    bfs();
    printf("%d\n%d\n",min_value-1,min_count);
}