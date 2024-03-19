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
    int arr[101];
    bool isPrime;
    int sum=0;

    //scanf("%d %d",&m,&n);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    //2~root(n)까지 나눠지는 숫자가 있으면 소수가 아님
    for(i=0;i<n;i++)
    {
        isPrime=TRUE;
        for(j=2;j<=sqrt(arr[i]);j++)
        {
            if(arr[i]%j==0){
                isPrime=FALSE;
                break;
            }
        }
        if(arr[i]==1) continue;
        if(isPrime)
            sum++;
    }
    printf("%d\n",sum);
    return 0;
}