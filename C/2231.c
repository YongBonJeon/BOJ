#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n;
    int i,x,j;
    int sum=0;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        sum=i;
        x=i;
        for(j=0;j<7;j++)
        {
            sum+=x%10;
            x/=10;
        }
        if(sum==n)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
  
}