#include <bits/stdc++.h>
using namespace std;

/* Slinding window or prefix sum*/

int main()
{
    int N,K;
    vector<int> input;
    int sum  = 0, max;

    scanf("%d %d",&N,&K);
    
    for(int i = 0 ; i < N ; i++)
    {
        int tmp;
        scanf("%d",&tmp);

        input.push_back(tmp);
    }
 
    for(int i = 0 ; i < K ; i++)
        sum += input[i];
    max = sum;
    
    for(int i = 0 ; i < N-K ; i++)
    {
        sum -= input[i];
        sum += input[i+K];

        if(sum > max)
            max = sum;
    }
    printf("%d\n",max);

}