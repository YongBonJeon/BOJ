#include <bits/stdc++.h>
using namespace std;

int N;
int m[65][65];

int check_area(int y, int x, int n)
{
    int s = m[y][x];
    //printf("s %d\n",s);
    for(int i = y ; i < y+n ; i++)
    {
        for(int j = x ; j < x+n ; j++)
        {
            //printf("%d ",m[i][j]);
            if(m[i][j] != s)
                return -1;
        }
    }
    //printf("\n");
    return s;
}

void recursion(int y, int x, int n)
{
    int rst;
    //printf("%d %d %d\n",y,x,n);
    if((rst = check_area(y,x,n)) >= 0)
    {
        printf("%d",rst);
    }
    else{
        printf("(");
        recursion(y, x, n/2);
        recursion(y, x+n/2 , n/2);
        recursion(y+n/2,x,n/2);
        recursion(y+n/2,x+n/2,n/2);
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
    printf("\n");
    
}