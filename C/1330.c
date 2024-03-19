#include <stdio.h>

int main()
{
    int a,b;

    scanf("%d %d",&a,&b);

    if(a<-10000||a>10000)
        return 0;
    if(b<-10000||b>10000)
        return 0;

    if(a>b)
        printf(">");
    else if(a<b)
        printf("<");
    else
        printf("==");

    return 0;
}