#include <bits/stdc++.h>
using namespace std;

int N;
stack<pair<int, int>> s;
int check[500001];

int main()
{
    scanf("%d",&N);

    int t,temp,ans = 0;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d",&t);

        if(s.empty())
        {
            s.push({t,1});
        }
        else
        {
            if(s.top().first < t)
            {
                temp = s.top().second;
                s.pop();
                if(!s.empty())
                    s.top().second += temp;
                s.push({t,1});
                ans += temp;
            }
            else if(s.top().first > t)
            {
                s.top().second++;
                s.push({t,1});
            }
        }
    }
}