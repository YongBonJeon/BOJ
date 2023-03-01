#include <bits/stdc++.h>
using namespace std;

int N,M,K;

int main()
{
    scanf("%d %d",&N, &M);
    scanf("%d",&K);

    int ans = 0;
    int cur = M;
    int apple;
    for(int i = 0 ; i < K ; i++)
    {
        scanf("%d",&apple);

        if(apple > cur)
        {
            ans += apple-cur;
            cur += apple-cur;
        }
        else if(apple < cur-M+1)
        {
            ans += cur-M+1-apple;
            cur = apple+M-1;
        }
    }
    printf("%d\n",ans);
}