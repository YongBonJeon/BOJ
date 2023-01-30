#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    bool year = 0;
    scanf("%d",&N);

    if(N%4 == 0)
    {
        if(N%400 == 0)
            year = 1;
        else if(N%100 == 0)
            year = 0;
        else
            year = 1;
    }
    printf("%d\n",year);
}