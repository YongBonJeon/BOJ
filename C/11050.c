#include <stdio.h>

int main()
{
    int N,K;
    
    scanf("%d %d", &N, &K);
    
    int ans = 1;
    for(int i = 0 ; i < K ; i++)
    {
        ans *= N-i;
        ans /= i+1;
    }

    printf("%d\n",ans);
}