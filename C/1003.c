#include <stdio.h>
#include <stdlib.h>

int fibo[41] = {0,};

int fibonacci(int m)
{
    

    fibonacci(m-1);
    fibonacci(m-2);
}

int main()
{
    int i,n,m;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf(" %d",&m);
        printf("%d %d\n",fibonacci0(m),fibonacci1(m));
        
    }
    return 0;
}