#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, H, W, N;

    scanf("%d",&T);

    for(int i = 0 ; i < T ; i++)
    {
        int a,b;
        scanf("%d %d %d",&H, &W, &N);

        a = N%H;
        b = N/H;
        
        if(a > 0)
            b++;
        else
            a = H;

        printf("%d\n",a*100+b);
    }
}