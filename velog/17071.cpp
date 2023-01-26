#include <bits/stdc++.h>
using namespace std;

int visited[500001];
int subin[600001];
int rev[600001];
int min_ = 5000000;
int N,K;

void bfs()
{
    int cur = N,next;
    queue<int> q;

    visited[cur] = 1;
    q.push(cur);

    while(!q.empty())
    {
        cur = q.front(); q.pop();
        if(cur > 1000)
            return ;
        printf("%d %d %d\n",cur,visited[cur]-1, subin[cur]);
        
        /*if(rev[visited[cur]-1] > 500000)
            return ;*/

        if(subin[cur] && subin[cur] == visited[cur]-1)
        {
            printf("%d %d %d\n",cur,visited[cur], subin[cur]);
            min_= min(min_, visited[cur]-1);
            return ;
        }

        
        if(subin[cur] && (subin[cur]-visited[cur]-1) % 2 == 0 && (subin[cur]-visited[cur]) > 0){
            min_ = min(min_, subin[cur]);
            continue;
        }

        for(int i = 0 ; i < 3 ; i++)
        {
            if(i == 0)
            {
                next = cur - 1;
                //if(rev[visited[next]] - next > )
            }
            else if(i == 1)
                next = cur + 1;
            else if(i == 2)
                next = cur * 2;

            /*if(next > K*100)
                return ;*/

            if(next < 0 || next > 500000)
                continue;

            //if(!visited[next])
            //{
                q.push(next);
                visited[next] = visited[cur] + 1;
            //}
        }

    }

}

int main()
{
    scanf("%d %d",&N, &K);

    for(int i = 0 ; K+(i*(i+1))/2 < 600000 ; i++)
    {
        subin[K+(i*(i+1))/2] = i;
        rev[i] = K+(i*(i+1))/2;
    }
    memset(visited,0,sizeof(visited));
    if(N != K)
        bfs();
    else
        min_ = 0;
    
    if(min_ == 5000000)
        min_ = -1;
    printf("%d\n",min_);

}

/* 
17 16 15 16 15
5   6  8 11 15
1 2 4 8 
1 2 4 7 11 15

17 18 20 
*/