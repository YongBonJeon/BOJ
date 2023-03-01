#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,a,b;

    scanf("%d",&T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d %d",&a,&b);

        printf("Case #%d: %d + %d = %d\n",i+1,a,b,a+b);
    }
}