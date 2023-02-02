#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,p,d;
    int select[10001] = {0,};
    priority_queue<pair<int,int>> pq;
    
    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d %d",&p, &d);

        pq.push({p,d});
    }

    int md = 0;
    for(int i = 0 ; i < N ; i++)
    {
        p = pq.top().first;
        d = pq.top().second;

        if(!select[d])
            select[d] = p;
        else
        {
            for(int j = d-1 ; j > 0 ; j--)
            {
                if(!select[j]){
                    select[j] = p;
                    break;
                }
                
            }
        }
        pq.pop();
        md = max(md,d);
    }
    int ans = 0;
    for(int i = 1 ; i <= md ; i++)
    {
        ans += select[i];
    }
    printf("%d\n",ans);
}