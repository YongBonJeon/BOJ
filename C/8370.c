#include <stdio.h>

int main()
{
    int n1,n2,k1,k2;
    int i;

    scanf("%d %d %d %d",&n1,&k1,&n2,&k2);

    if(n1<0||n1>1000)
        return 0;
    if(n2<0||n2>1000)
        return 0;
    if(k1<0||k1>1000)
        return 0;
    if(k2<0||k2>1000)
        return 0;

    printf("%d\n",n1*k1+n2*k2);

    return 0;
}