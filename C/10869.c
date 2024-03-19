#include <stdio.h>

int main()
{
    int m,n;

    scanf("%d %d",&m,&n);

    if(m<1||m>10000)
        return 0;
    if(n<1||n>10000)
        return 0;

    printf("%d\n%d\n%d\n%d\n%d\n",m+n,m-n,m*n,m/n,m%n);

    return 0;
}