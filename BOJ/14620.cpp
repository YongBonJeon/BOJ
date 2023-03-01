#include <bits/stdc++.h>
using namespace std;

int N;
int m[11][11];
int visited[11][11];
int min_ = 10000000;

void select(int num, int val)
{
    if(num == 3){
        min_ = min(min_, val);
        return ;
    }

    for(int i = 1 ; i < N-1 ; i++)
    {
        for(int j = 1 ; j < N-1 ; j++)
        {
            if(!visited[i][j] && !visited[i-1][j] && !visited[i][j-1] && !visited[i+1][j] && !visited[i][j+1])
            {
                int temp_val = m[i][j]+m[i-1][j]+m[i][j-1]+m[i+1][j]+m[i][j+1];
                visited[i][j]=1; visited[i-1][j]=1; visited[i][j-1]=1; visited[i+1][j]=1; visited[i][j+1]=1;
                select(num+1, val+temp_val);
                visited[i][j]=0; visited[i-1][j]=0; visited[i][j-1]=0; visited[i+1][j]=0; visited[i][j+1]=0;
            }
        }
    }
}

int main()
{
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            scanf("%d",&m[i][j]);

    memset(visited,0,sizeof(visited));

    select(0,0);

    printf("%d\n",min_);

}