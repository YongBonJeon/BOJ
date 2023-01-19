#include <bits/stdc++.h>
using namespace std;

int N,L,R;
int A[51][51];
int visited[51][51];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<pair<int, int>> _union;

void select_union(int y, int x, int num)
{
    queue<pair<int,int>> q;
    int ny,nx, count = 0;

    q.push({y,x});
    visited[y][x] = num;

    while(!q.empty())
    {
        tie(y,x) = q.front(); q.pop();

        for(int i = 0 ; i < 4 ; i++)
        {
            ny = y + dy[i];
            nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;

            if(visited[ny][nx] != num)
            {
                if(abs(A[ny][nx]-A[y][x]) >= L && abs(A[ny][nx]-A[y][x]) <= R)
                {
                    visited[ny][nx] = num;
                    count++;
                    q.push({ny, nx});
                }
            }
        }
    }
    if(count == 0)
        visited[y][x] = 0;
}

void move(int y, int x)
{
    int total = 0, num = visited[y][x], count = 0; 

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
            if(visited[i][j] == num)
            {
                total += A[i][j];
                count++;
            }
    }
    int move = total/count;

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
            if(visited[i][j] == num)
            {
                A[i][j] = move;
                visited[i][j] = 0;
            }
    }
}

int main()
{
    int final[51][51];
    scanf("%d %d %d",&N, &L, &R);

    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            scanf("%d",&A[i][j]);
            final[i][j] = i*N+j+1;
        }
    }



    int ans = 0;
    while(1)
    {
        //printf("%d\n\n",ans);
        int num = 1;
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                if(!visited[i][j])
                    select_union(i,j, num++);
            
        /*for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                printf("%d ",visited[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
            }
        }

        int fin = 0;
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                if(visited[i][j] == 0)
                    fin++;
            }
        }
    //printf("fin %d\n",fin);
        if(fin == N*N)
            break;



        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                if(visited[i][j] > 0)
                    move(i,j);
            

        /*for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                printf("%d ",A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
            for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                printf("%d ",visited[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        }
        }

        ans++;
    }
    
    printf("%d\n",ans);
}