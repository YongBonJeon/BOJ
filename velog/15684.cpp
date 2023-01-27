#include <bits/stdc++.h>
using namespace std;

int N,M,H;
int m[31][11];
int min_ = 99;

bool game()
{
    for(int i = 1 ; i <= N ; i++)
    {
        int v = i;

        for(int level = 1 ; level <= H ; level++)
        {
            if(m[level][v] == 1)
                v++;
            else if(m[level][v-1] == 1)
                v--;
        }
        if(v != i)
            return false; 
    }
    return true;
}

void add_ladder(int cur, int num)
{
    if(num <= 3)
    {
        if(game())
            min_ = min(min_, num);
    }
    else
        return ;

    for(int level = cur ; level <= H ; level++)
    {
        for(int i = 1 ; i < N ; i++)
        {
            if(m[level][i] == 1)
                continue;
            if(m[level][i+1] == 1 || m[level][i-1] == 1)
                continue;

            m[level][i] = 1;
            add_ladder(level, num+1);
            m[level][i] = 0;
        }
    }
}

int main()
{
    scanf("%d %d %d",&N,&M,&H);

    int level, v;
    for(int i = 0 ; i < M ; i++)
    {
        scanf("%d %d",&level, &v);

        m[level][v] = 1;
    }
    
    add_ladder(1,0);

    if(min_ > 3)
        printf("-1\n");
    else
        printf("%d\n",min_);
}