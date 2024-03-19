#include <stdio.h>

int main()
{
    long long m,n; //m<n 
    int i;
    int gcb,lcm;
    scanf("%d %d",&m,&n);

    if(m>n)
    {
        int temp= m;
        m=n;
        n=temp;
    }

    for(i=1;i<=m;i++)
    {
        if((m%i==0)&&(n%i==0))
            gcb=i;
    }
    lcm=m*n/gcb;
    printf("%d\n%d\n",gcb,lcm);
    
    return 0;
}