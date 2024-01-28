#include<bits/stdc++.h>
using namespace std;

/* nCm = n! / m! / (n-m)!*/

int main()
{
    long long n, m;

    cin >> n >> m;

    if(m > n-m)
        m = n-m;

    long long ans = 1;

    /*for(long long i = n-m+1 ; i <= n ; i++){
        printf("%lld %lld\n",i,n-i+1);
        ans *= i;
        ans /= (n-i+1);
    }*/
    for(long long i = n ; i >= n-m+1 ; i--){
        //printf("%lld %lld\n",i,n-i+1);
        ans *= i;
        ans /= (n-i+1);
    }

    printf("%lld\n",ans);
}