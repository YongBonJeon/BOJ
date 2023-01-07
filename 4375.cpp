#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    while(scanf("%lld",&N) != EOF)
    {
        long long x = 1, num = 0;
        //printf("%lld\n",N);
        while(1)
        {
            //printf("%lld\n",x);
            if(x%N == 0)
            {
                printf("%lld\n",num+1);
                break;
            }
            else
            {
                x *= 10;
                x += 1;
                x %= N;
                num++;
            }
        }
    }
}