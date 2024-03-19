#include <stdio.h>

int main()
{
    int m,n;

    scanf("%d",&m);
    scanf("%d",&n);
    if(m<0||n<0)
        return 0;
    if(m>=10||n>=10)
        return 0;

    printf("%d\n",m+n);
    return 0;
}