#include <bits/stdc++.h>
using namespace std;

int d[20001] = {0,};

int main()
{
    for(int i = 1 ; i <= 10000 ; i++)
    {
        int t = i, ans = i;

        while(t)
        {
            ans += t%10;
            t /= 10;
        }
        //printf("%d %d\n",ans,i);
        d[ans] = i;
    }
    for(int i = 1 ; i <= 10000 ; i++)
        if(!d[i])
            printf("%d\n",i);
}