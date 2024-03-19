#include <stdio.h>

int main()
{
    int n;
    
    scanf("%d",&n);

    if(n<0||n>10000)
        return 0;

    printf("%d\n",n*(n+1)/2);

    return 0;
}