#include <stdio.h>

int main()
{
    int r1,r2,s;

    scanf("%d %d",&r1,&s);

    if(r1>1000||r1<-1000)
        return 0;
    if(s>1000||s<-1000)
        return 0;

    r1=(s*2)-r1;

    printf("%d\n",r1);

    return 0;
}