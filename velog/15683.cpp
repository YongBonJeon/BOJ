#include <bits/stdc++.h>
using namespace std;

int N,M;
// 동남서북
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

typedef struct _cctv{
    int y;
    int x;
    int dir;
}cctv;

vector<cctv> cctvs;
int min_ = 100;
void backtracking(int num, int m[9][9])
{
    /*for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/

    // base case
    if(num == cctvs.size()){
        int t = 0;
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < M ; j++)
                if(m[i][j] == 0)
                    t++;
        min_ = min(min_,t);
        return ;
    }

    int temp[9][9];

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            temp[i][j] = m[i][j];

    int dir = cctvs[num].dir;
    int y = cctvs[num].y;
    int x = cctvs[num].x;
    int ny = y,nx = x;

    // 1번 방향 
    if(dir == 1){
        for(int i = 0 ; i < 4 ; i++){
            while(1){
                ny += dy[i];
                nx += dx[i];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M || m[ny][nx] == 6)
                    break;
                
                if(!m[ny][nx])
                    temp[ny][nx] = '#';
            }
            backtracking(num+1, temp);
            for(int i = 0 ; i < N ; i++)
                for(int j = 0 ; j < M ; j++)
                    temp[i][j] = m[i][j];
            ny = y;
            nx = x;
        }
    }
    // 2번 방향
    else if(dir == 2){
        for(int i = 0 ; i < 2 ; i++){
            while(1){
                ny += dy[i];
                nx += dx[i];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M || m[ny][nx] == 6)
                    break;
                
                if(!m[ny][nx])
                    temp[ny][nx] = '#';
            }
            ny = y;
            nx = x;
            while(1){
                ny += dy[i+2];
                nx += dx[i+2];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M || m[ny][nx] == 6)
                    break;
                
                if(!m[ny][nx])
                    temp[ny][nx] = '#';
            }
            backtracking(num+1, temp);
            for(int i = 0 ; i < N ; i++)
                for(int j = 0 ; j < M ; j++)
                    temp[i][j] = m[i][j];
            ny = y;
            nx = x;
        }
    }
    else if(dir == 3){
        for(int i = 0 ; i < 4 ; i++){
            while(1){
                ny += dy[i%4];
                nx += dx[i%4];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M || m[ny][nx] == 6)
                    break;
                
                if(!m[ny][nx])
                    temp[ny][nx] = '#';
            }
            ny = y;
            nx = x;
            while(1){
                ny += dy[(i+1)%4];
                nx += dx[(i+1)%4];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M || m[ny][nx] == 6)
                    break;
                
                if(!m[ny][nx])
                    temp[ny][nx] = '#';
            }
            backtracking(num+1, temp);
            for(int i = 0 ; i < N ; i++)
                for(int j = 0 ; j < M ; j++)
                    temp[i][j] = m[i][j];
            ny = y;
            nx = x;
        }
    }
    // 4번 방향
    else if(dir == 4){
        for(int i = 0 ; i < 4 ; i++){
            while(1){
                ny += dy[i%4];
                nx += dx[i%4];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M || m[ny][nx] == 6)
                    break;
                
                if(!m[ny][nx])
                    temp[ny][nx] = '#';
            }
            ny = y;
            nx = x;
            while(1){
                ny += dy[(i+1)%4];
                nx += dx[(i+1)%4];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M || m[ny][nx] == 6)
                    break;
                
                if(!m[ny][nx])
                    temp[ny][nx] = '#';
            }
            ny = y;
            nx = x;
            while(1){
                ny += dy[(i+2)%4];
                nx += dx[(i+2)%4];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M || m[ny][nx] == 6)
                    break;
                
                if(!m[ny][nx])
                    temp[ny][nx] = '#';
            }
            backtracking(num+1, temp);
            for(int i = 0 ; i < N ; i++)
                for(int j = 0 ; j < M ; j++)
                    temp[i][j] = m[i][j];
            ny = y;
            nx = x;
        }
    }
    else if(dir == 5){
        for(int i = 0 ; i < 4 ; i++){
            ny = y;
            nx = x;
            while(1){
                ny += dy[i];
                nx += dx[i];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M || m[ny][nx] == 6)
                    break;
                
                if(!m[ny][nx])
                    temp[ny][nx] = '#';
            }
        }
        backtracking(num+1, temp);
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < M ; j++)
                temp[i][j] = m[i][j];
    }


    
}

int main()
{
    int m[9][9];
    cctv object;

    scanf("%d %d",&N, &M);
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%d",&m[i][j]);
            if(m[i][j] && m[i][j] < 6){
                object.y = i;
                object.x = j;
                object.dir = m[i][j];
                cctvs.push_back(object);
                //printf("%d %d %d\n",object.y,object.x,object.dir);
            }
        }
    }

    backtracking(0,m);
    printf("%d\n",min_);
}