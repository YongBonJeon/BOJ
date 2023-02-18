#include <bits/stdc++.h>
using namespace std;

int N,K,L;
int M[101][101];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
char ch[10001];
deque<pair<int,int>> dq;

int game()
{
    int time = 0, dir = 0;
    int ny,nx;
    dq.push_front({0,0});

    while(1){
        switch(ch[time])
        {
            case 'D':
                dir = (dir+1)%4;
                break;
            case 'L':
                dir = (dir-1)%4;
                if(dir < 0)
                    dir += 4;
                break;
        }

        ny = dq.front().first + dy[dir];
        nx = dq.front().second + dx[dir];

        /* 벽 부딪힘*/
        if(ny < 0 || nx < 0 || ny >= N || nx >= N)
            break;
        
        /* 몸 부딪힘 */
        bool crash = false;
        for(auto tail : dq)
            if(tail.first == ny && tail.second == nx)
                crash = true;
        if(crash)
            break;

        /* 몸 늘림 */
        dq.push_front({ny,nx});
        
        /* 사과 */
        if(M[ny][nx])
            M[ny][nx] = 0;  
        /* 사과 X */
        else
            dq.pop_back();

        time++;
    }
    return time;
}

int main()
{
    scanf("%d %d",&N,&K);
    int y,x,t;
    char c;
    for(int i = 0 ; i < K ; i++)
    {
        scanf("%d %d",&y,&x);
        M[y-1][x-1] = 1;
    }
    scanf("%d",&L);
    for(int i = 0 ; i < L ; i++){
        scanf(" %d %c",&t, &c);
        ch[t] = c;
    }

    printf("%d\n",game()+1);
}