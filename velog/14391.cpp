#include <bits/stdc++.h>
using namespace std;

int N,M;
char m[5][5];
int visited[5][5];

/*void select()
{

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            if(check[i][j] == 0 && check[i][j+1] == 0)
            {
                check[i][j] = 1; 
                check[i][j+1] = 1;
                asdf;
                check[i][j] = 1;
                check[i][j+1] = 1;
            }

            if(check[i][j] == 0 && check[i][j+1] == 0 && check[i][j+2] == 0)
            {
                check[i][j] = 1; 
                check[i][j+1] = 1;
                check[i][j+2] = 1;
                asdf;
                check[i][j] = 1;
                check[i][j+1] = 1;
                check[i][j+2] = 1;
            }

            if(check[i][j] == 0 && check[i][j+1] == 0 && check[i][j+2] == 0 && check[i][j+3] == 0)
            {
                check[i][j] = 1; 
                check[i][j+1] = 1;
                check[i][j+2] = 1;
                check[i][j+3] = 1;
                asdf;
                check[i][j] = 1;
                check[i][j+1] = 1;
                check[i][j+2] = 1;
                check[i][j+3] = 1;
            }


        }
    }
}*/

int dy[2] = {1,0};
int dx[2] = {0,1};

void fs(int y, int x, int num, int dir)
{
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    visited[y][x] = num;

    if(ny < 0 || nx < 0 || ny >= N || ny >= M || visited[ny][nx] != 0)
        return ;
    
    fs(ny,nx,num,dir);

}

void select()
{

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            if(!visited[i][j])
            {
                
            }
        }
    }

}

int main()
{
    scanf("%d %d",&N,&M);

    for(int i = 0 ; i < N ; i++)
        scanf("%s",m[i]);
}