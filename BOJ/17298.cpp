#include<bits/stdc++.h>
using namespace std;

int N;

int main()
{
    scanf("%d",&N);
    
    stack<pair<int, int>> s;
    vector<int> ans(N);
    int num;

    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&num);

        if(s.empty())
            s.push({i,num});
        else{
            while((!s.empty()) && num > s.top().second)
            {
                ans[s.top().first] = num;
                s.pop();
            }
            s.push({i,num});
        }
    }

    for(int i = 0 ; i < N ; i++)
    {
        if(ans[i] == 0)
            printf("-1 ");
        else
            printf("%d ",ans[i]);
    }
    printf("\n");
}