#include <bits/stdc++.h>
using namespace std;

int N;
int m[65][65];

int check_area(int y, int x, int n)
{
    int s = m[y][x];
    for(int i = y ; i < n ; i++)
    {
        for(int j = x ; j < n ; j++)
        {
            if(m[i][j] != s)
                return -1;
        }
    }
    return s;
}

void recursion(int y, int x, int n)
{
    int rst;
    if((rst = check_area(y,x,n)) >= 0)
    {
        printf("%d",rst);
    }
    else{
        printf("(");
        recursion(x, x, n/2);
        recursion(x, x+n/2 , n/2);
        recursion(x+n/2,x,n/2);
        recursion(x+n/2,x+n/2,n/2);
        printf(")");
    }
    
}

int main()
{
    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            scanf("%1d",&m[i][j]);

    recursion(0,0,N);
    
}