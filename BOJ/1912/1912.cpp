#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,t;
    
    vector<int> sequence;

    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&t);
        sequence.push_back(t);
    }

    int max_ = -1010, sum = 0;
    for(auto x : sequence){
        sum += x;
        max_ = max(max_,sum);
        if(sum < 0)
            sum = 0;
        
    }
    printf("%d\n",max_);

}