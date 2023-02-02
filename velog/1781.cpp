#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<pair<int,int>> pq;
int sel[200001] = {0,};

int main()
{   
    scanf("%d",&N);

    int d,w;
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d %d",&d,&w);

        pq.push({w,d});
    }
    
    int ans = 0, md = 0;
    for(int i = 0 ; i < N ; i++)
    {
        d = pq.top().second;
        w = pq.top().first;

        for(int j = d ; j > 0 ; j--)
        {
            if(!sel[j]){
                sel[j] = w;
                ans += w;
                break;
            }
        }
        pq.pop();
    }
    
    printf("%d\n",ans);

}