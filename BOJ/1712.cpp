#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c;

    scanf("%lld %lld %lld",&a,&b,&c);

    /* a + b*n  < c * n */

   // a + (b-c)*n < 0

    //a < (c-b)*n
    if(b == c)
        printf("-1\n");
    else if(a/(c-b) + 1 <= 0)
        printf("-1\n");
    else
        printf("%lld\n",a/(c-b) + 1);


}