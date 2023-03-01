#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, ans = 0;

    scanf("%d",&N);

    if(N < 100)
        ans = N;
    else
        ans = 99;

    for(int i = 100 ; i <= N ; i++)
    {
        int a,b,c,t;
        t = i;
        c = t%10;
        b = (t/10)%10;
        a = (t/100);

        if(a+c == b*2)
            ans++;
    }
    printf("%d\n",ans);
}