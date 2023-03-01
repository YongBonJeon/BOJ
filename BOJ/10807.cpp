#include <bits/stdc++.h>
using namespace std;

int x[201] = {0,};

int main()
{
    int N,t;

    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&t);
        
        x[t+100]++;
    }
    scanf("%d",&t);
    printf("%d\n",x[t+100]);
}