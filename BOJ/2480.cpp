#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,B,C,max_;

    scanf("%d %d %d",&A, &B, &C);

    if(A == B && B == C)
    {
        printf("%d\n",10000 + A*1000);
    }
    else if(A == B && A != C)
    {
        printf("%d\n",1000+A*100);
    }
    else if(A == C && A != B)
    {
        printf("%d\n",1000+A*100);
    }
    else if(B == C && A != B)
    {
        printf("%d\n",1000+B*100);
    }
    else
    {
        max_ = max(A,B);
        max_ = max(max_,C);

        printf("%d\n",max_*100);
    }
}