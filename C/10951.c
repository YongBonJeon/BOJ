#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;

    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a<0||a>10)
            break;
        else if(b<0||b>10)
            break;
        else
            printf("%d\n",a+b);
    }
    return 0;
}