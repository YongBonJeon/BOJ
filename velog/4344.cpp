#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,N,sum = 0,num = 0;
    int x[1001];

    scanf("%d",&T);
    
    for(int i = 0 ; i < T ; i++)
    {
        memset(x,0,sizeof(x));
        num = 0;
        sum = 0;
        scanf("%d",&N);
        for(int j = 0 ; j < N ; j++)
        {
            scanf("%d",&x[j]);
            sum += x[j];
        }
        for(int j = 0 ; j < N ; j++)
        {
            if(x[j] > sum/N)
                num++;
        }
        printf("%.3f%\%\n",(double)num/(double)N*100.0);
    }
}