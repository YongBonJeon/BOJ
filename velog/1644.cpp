#include <bits/stdc++.h>
using namespace std;

bool prime[4000001];
int N;

int main()
{
    scanf("%d",&N);

    for(int i = 2 ; i <= N ; i++)
        prime[i] = 1;

    for(int i = 2 ; i <= N ; i++)
    {
        if(!prime[i])
            continue;
        for(int j = i+i ; j <= N ; j += i)
            prime[j] = 0;
    }

    int l = 2, r = 3;
    int sum_prime = l+r, ans = 0;

    while(l <= N && r <= N)
    {
        if(sum_prime < N)
        {
            r++;
            while(!prime[r])
                r++;
            
            sum_prime += r;
        }
        else if(sum_prime > N)
        {
            sum_prime -= l;
            
            l++;
            while(!prime[l])
                l++;
        }
        else if(sum_prime == N)
        {
            sum_prime -= l;
            
            l++;
            while(!prime[l])
                l++;
            ans++;
        }
    }
    if(N == 2)
        ans++;
    printf("%d\n",ans);
}