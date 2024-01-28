#include <bits/stdc++.h>
using namespace std;

long long solve(long long a, long long b, long long c)
{
    if(b == 1)
        return a % c;
    long long result = solve(a, b/2, c);
    result = (result*result) % c;
    if(b % 2)
        result = (result*a) % c;
    return result;
}

int main()
{
    long long A,B,C;

    scanf("%lld %lld %lld",&A,&B,&C);

    printf("%lld\n",solve(A,B,C));
}