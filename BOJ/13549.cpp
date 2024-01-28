#include <bits/stdc++.h>
using namespace std;

int N,K;
int m[100001];
int visited[100001];
queue<int> q;

void fs()
{
    int nextv, cur;
    visited[N] = 1;
    q.push(N);

    while(!q.empty()){
        cur = q.front(); q.pop();
        //printf("%d\n",cur);

        if(cur == K){
            //printf("sinba~\n");
            return ;
        }

    for(int i = 0 ; i < 3 ; i++)
    {
        
        switch(i){
            case 0 :
                nextv = cur*2;
                if(nextv >= 0 && nextv <= 100000)
                {
                    if(visited[nextv] > visited[cur])
                        visited[nextv] = visited[cur];
                }
                if(nextv >= 0 && nextv <= 100000 && visited[nextv] == 0)
                {
                    q.push(nextv);
                    visited[nextv] = visited[cur];
                }
                //break;
            case 1 :
                nextv = cur+1;
                if(nextv >= 0 && nextv <= 100000)
                {
                    if(visited[nextv] > visited[cur] + 1)
                        visited[nextv] = visited[cur] + 1;
                }
                if(nextv >= 0 && nextv <= 100000 && visited[nextv] == 0)
                {
                    q.push(nextv);
                    visited[nextv] = visited[cur] + 1;
                }
                //break;
            case 2 :
                nextv = cur-1;
                if(nextv >= 0 && nextv <= 100000)
                {
                    if(visited[nextv] > visited[cur] + 1)
                        visited[nextv] = visited[cur] + 1;
                }
                if(nextv >= 0 && nextv <= 100000 && visited[nextv] == 0)
                {
                    q.push(nextv);
                    visited[nextv] = visited[cur] + 1;
                }
                //break;
        }
    }

    }
    
}

int main()
{
    scanf("%d %d",&N,&K);

    memset(visited,0,sizeof(visited));

    fs();

    printf("%d\n",visited[K]-1);
}