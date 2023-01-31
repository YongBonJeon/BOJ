#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X,N,a,b;

    scanf("%d %d",&X, &N);

    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d %d",&a,&b);

        X -= a*b;
    }
    if(X)
        printf("No\n");
    else
        printf("Yes\n");
}