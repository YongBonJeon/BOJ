#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int main()
{
    int m,n; //m<=n
    int i,j;
    double root;
    bool isPrime;

    scanf("%d %d",&m,&n);

    //2~root(n)까지 나눠지는 숫자가 있으면 소수가 아님
    for(i=m;i<=n;i++)
    {
        isPrime=TRUE;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0){
                isPrime=FALSE;
                break;
            }
        }
        if(i==1) continue;
        if(isPrime)
            printf("%d\n",i);
    }
    return 0;
}