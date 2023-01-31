#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,B,C;

    scanf("%d %d %d",&A, &B, &C);

    B += C;
    if(B >= 60)
    {
        A += B/60;
        if(A >= 24)
            A %= 24;
        B %= 60;
    }
    printf("%d %d\n",A,B);
}