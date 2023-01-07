#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, less<int>> maxheap;
    int N;

    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        if(tmp == 0)
        {
            if(maxheap.empty())
                printf("0\n");
            else{
                printf("%d\n",maxheap.top());
                maxheap.pop();
            }
        }
        else
            maxheap.push(tmp);
    }

}