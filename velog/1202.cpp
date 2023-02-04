#include <bits/stdc++.h>
using namespace std;

int N,K;
pair<int,int> jewel[300001];
int back[300001];
priority_queue<int> pq;

int main()
{
    scanf("%d %d",&N, &K);
    int m,v,b;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d %d",&m,&v);
        jewel[i] = {m,v};
    }
    for(int i = 0 ; i < K ; i++)
    {
        scanf("%d",&b);
        back[i] = b;
    }
    sort(back, back + K);
    sort(jewel, jewel + N);

    int idx = 0, sum = 0;
    for(int i = 0 ; i < K ; i++)
    {
        while(idx < N && jewel[idx].first <= back[i])
        {
            pq.push(jewel[idx++].second);
        }
        if(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }
    printf("%d\n",sum);
}