#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x[31] = {0,},t;

    for(int i = 0 ; i < 28 ; i++)
    {
        scanf("%d",&t);
        x[t] = 1;
    }
    for(int i = 1 ; i <= 30 ; i++)
        if(!x[i])
            printf("%d\n",i);
}