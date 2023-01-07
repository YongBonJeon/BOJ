#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    scanf("%d",&N);
    scanf("%d",&M);

    vector<int> input(N);

    for(int i = 0 ; i < N ; i++)
        scanf("%d",&input[i]);
    
    sort(input.begin(),input.end());

    int l=0,r=input.end()-input.begin()-1;
    
    int count = 0;
    while(l < r)
    {
        int sum = input[l] + input[r];
        //printf("%d ",sum);
        if(sum < M)
            l++;
        else if(sum > M)
            r--;
        else{
            l++;
            r--;
            count++;
        }
    }
    printf("%d\n",count);
}