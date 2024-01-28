#include <bits/stdc++.h>
using namespace std;

int N,M;
int m[101][101];

int main()
{
    int q;
    scanf("%d %d",&N, &M);

    memset(m,0,sizeof(m));
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            scanf("%d",&q);
            m[i][j] += q;
        }
    }
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}