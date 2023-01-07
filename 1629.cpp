#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,B,C;

    scanf("%d %d %d",&A,&B,&C);

    // A^B%C
    int ans = 1;

    for(int i = 0 ; i < B ; i++)
    {
        ans = (ans*(A%C))%C;
    }
    printf("%d\n",ans);
}