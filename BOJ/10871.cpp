#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,X,t;

    scanf("%d %d",&N,&X);

    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&t);

        if(t < X)
            printf("%d ",t);
    }
    printf("\n");
}