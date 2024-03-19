#include <stdio.h>

int main()
{
    long double a,b;

    scanf("%Lf %Lf",&a,&b);
    if(a<=0||a>=10)
        return 0;
    if(b<=0||b>=10)
        return 0;
    printf("%.20Lf\n",a/b);

    return 0;
}