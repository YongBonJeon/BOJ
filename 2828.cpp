#include <bits/stdc++.h>
using namespace std;

int N,M,K;

int main()
{
    scanf("%d %d",&N, &M);
    scanf("%d",&K);

    int ans = 0;
    int cur = M;
    int ap;
    for(int i = 0 ; i < K ; i++)
    {
        scanf("%d",&ap);

        if(ap > cur)
        {
            ans += ap-cur;
            cur += ap-cur;
        }
        else if(ap < cur-M+1)
        {
            ans += cur-M+1-ap;
            cur = ap+M-1;
        }
        //printf("%d %d\n",cur, ans);
    }
    printf("%d\n",ans);
}