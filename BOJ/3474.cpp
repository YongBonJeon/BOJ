#include<bits/stdc++.h>
using namespace std;

map<int, int> ans;
vector<int> input;

int solve(int n)
{
    int num_5 = 0;

    for(int i = 5 ; i <= n ; i*=5)
    {
        num_5 += n / i;
    }
    return num_5;
}

int main()
{
    int num_TC;

    scanf("%d",&num_TC);

    for(int i = 0 ; i < num_TC ; i++)
    {
        int N;

        scanf("%d",&N);

        printf("%d\n",solve(N));
    }
}