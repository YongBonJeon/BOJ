#include <bits/stdc++.h>
using namespace std;

int x;
int ans = 0;

int main()
{
    scanf("%d",&x);

    for(int i = 0 ; i < 8 ; i++)
    {
        if((x & 1))
            ans++;
        x >>= 1;
    }
    printf("%d\n",ans);
}